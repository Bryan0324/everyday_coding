from threads.api import ThreadsAPI
import sys
import json

import requests
import json
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

def refresh_token():
    with open("secret.json", "r", encoding="utf-8") as file:
        ori = json.loads(file.read())
        access_token = ori["access_token"]
    if not access_token:
        raise ValueError("THREADS_ACCESS_TOKEN 環境變數未設定")

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
    print(f"新的 Access Token: {new_token}")
    print(f"有效期: {expires_in // 86400} 天")

    # 輸出到檔案（方便手動檢查/存放）
    with open("secret.json", "w", encoding="utf-8") as f:
        ori["access_token"] = new_token
        json.dump(ori, f, indent=2, ensure_ascii=False)

    return new_token


# 從 git hook 傳進來的參數
commit_message = sys.argv[1]
changed_files = sys.argv[2:]
refresh_token()
with open("secret.json", "r", encoding="utf-8") as file:
    raw = json.loads(file.read())
    threads = ThreadsAPI(
        user_id = raw["user_id"],
        access_token=raw["access_token"],
        app_secret=raw["app_secret"]
    )


    
# 組合發文內容
text = "TOI初選錄取前每日一題競程"
text += commit_message + "\n"

text += "\n\n" + "今日的程式碼：\n"

for i in changed_files:
    text += "https://github.com/Bryan0324/everyday_coding/blob/main/" + i + "\n"


parts = split_text(text)
container_ids = []

# 先建立所有 container
for i, part in enumerate(parts):
    if i == 0:
        media_json = threads.create_media_container(text=part)
    else:
        media_json = threads.create_media_container(text=part)
        media_json.update({"text_post_app_info": {"reply_id": container_ids[-1]}})
    container_ids.append(media_json.get("id"))

# 發佈所有 container（會自動串成 thread）
for cid in container_ids:
    resp = threads.publish_container(cid)
    print("Published:", resp)