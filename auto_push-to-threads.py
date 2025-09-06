from threads.api import ThreadsAPI
import sys
import json
# 從 git hook 傳進來的參數
commit_message = sys.argv[1]
changed_files = sys.argv[2:]
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