from threads.api import ThreadsAPI
import sys
import json
import os

import requests

def raw_container(text, token, user_id, reply_id=None, media_type="TEXT"):
    params = {
            "text": text,
            "access_token": token,
            "media_type": media_type,  # TEXT, IMAGE, VIDEO
        }
    if reply_id:
        params["reply_to_id"] = reply_id
    resp = requests.post(
            f"https://graph.threads.net/v1.0/{user_id}/threads",
            params=params,
        )
    return resp.json()

def split_text(text, limit=490):  # 留一點 buffer
    _ret = text.split('\n')
    ret = []
    for line in _ret:
        if len(line) > limit:
            ret.extend([line[i:i+limit] for i in range(0, len(line), limit)])
        elif len(ret) == 0 or len(ret[-1]) + len(line) + 1 > limit:
            ret.append(line)
        else:
            ret[-1] += '\n' + line
    return ret

def refresh_token(access_token=None, persist=False, ori=None):
    """Refresh access token.

    If `access_token` is provided, use it. If `persist` is True and an
    `ori` dict is provided (from secret.json), write the refreshed token back.
    In CI (when using Actions Secrets) `persist` should be False so we don't
    attempt to write files.
    """
    if not access_token:
        raise ValueError("THREADS_ACCESS_TOKEN 未設定（env 或 secret.json）")

    url = "https://graph.threads.net/refresh_access_token"
    params = {
        "grant_type": "th_refresh_token",
        "access_token": access_token,
    }

    print("正在更新 Threads 長期存活 Token...")
    resp = requests.get(url, params=params)
    data = resp.json()

    if "access_token" not in data:
        raise RuntimeError(f"更新失敗: {data}")

    new_token = data["access_token"]
    expires_in = data.get("expires_in", 0)

    print("更新成功")
    print(f"新的 Access Token: {new_token[:10]}...{new_token[-10:]}")
    print(f"有效期: {expires_in // 86400} 天")

    return new_token


def load_secrets():
    """Load secrets from environment (preferred) or fallback to secret.json."""
    user_id = os.getenv("THREADS_USER_ID")
    access_token = os.getenv("THREADS_ACCESS_TOKEN")
    app_secret = os.getenv("THREADS_APP_SECRET")
    if user_id and access_token and app_secret:
        return {"user_id": user_id, "access_token": access_token, "app_secret": app_secret, "persist": False}

    # fallback to file
    with open("secret.json", "r", encoding="utf-8") as file:
        ori = json.loads(file.read())
    return {"user_id": ori.get("user_id"), "access_token": ori.get("access_token"), "app_secret": ori.get("app_secret"), "persist": True, "ori": ori}


# 從 git hook 傳進來的參數
commit_message = sys.argv[1]
changed_files = sys.argv[2:]

# 取得 secrets（優先使用 env）
secrets = load_secrets()

# 嘗試更新 token，但只有當 secrets 從 secret.json 讀入時才會被寫回檔案
new_token = refresh_token(secrets.get("access_token"), persist=secrets.get("persist", False), ori=secrets.get("ori"))
if new_token:
    access_token = new_token
else:
    access_token = secrets.get("access_token")

threads = ThreadsAPI(
    user_id=secrets.get("user_id"),
    access_token=access_token,
    app_secret=secrets.get("app_secret"),
)
    
# 組合發文內容
text = "TOI初選錄取前每日一題競程"
text += commit_message + "\n"

text += "\n\n" + "今日的程式碼：\n"
for i in changed_files:
    text += "https://github.com/Bryan0324/everyday_coding/blob/main/" + i + "\n"
parts = split_text(text)

if commit_message == "test":
    print("Test mode, not posting to Threads.")
    sys.exit(0)

container_ids = []

# 先建立所有 container
for i, part in enumerate(parts):
    if i == 0:
        media_json = raw_container(part, access_token, secrets.get("user_id"))
    else:
        media_json = raw_container(part, access_token, secrets.get("user_id"), reply_id=container_ids[-1])
    print("Created container:", media_json)
    container_ids.append(media_json.get("id"))
    resp = threads.publish_container(container_ids[-1])
    print("Published:", resp)
print("All done!")