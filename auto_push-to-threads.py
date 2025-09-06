from threads.api import ThreadsAPI
import sys
import json

import requests
import json

def refresh_token():
    with open("secret.json", "r", encoding="utf-8") as file:
        ori = file.read()
        access_token = ori["access_token"]
    if not access_token:
        raise ValueError("❌ THREADS_ACCESS_TOKEN 環境變數未設定")

    url = "https://graph.threads.net/refresh_access_token"
    params = {
        "grant_type": "th_refresh_token",
        "access_token": access_token,
    }

    print("🔄 正在更新 Threads 長期存活 Token...")
    resp = requests.get(url, params=params)
    data = resp.json()

    if "access_token" not in data:
        raise RuntimeError(f"❌ 更新失敗: {data}")

    new_token = data["access_token"]
    expires_in = data.get("expires_in", 0)

    print("✅ 更新成功")
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
text += "\n".join(changed_files)

# 建立發文 Container
media_json = threads.create_media_container(text=text)
print("Container:", media_json)

# 將 Container 發文
threads.publish_container(media_json.get("id"))