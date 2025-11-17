# every_day_coding — 使用手冊

目標
- 自動把 GitHub push 的變更檔案與 commit 訊息發到 Threads（使用 Facebook/Meta Graph API）。
- 用 GitHub Actions 在 main 分支 push 時觸發，CI 中以 Actions Secrets 提供憑證。

目錄
- 檔案清單
- 需求
- 快速啟動
- GitHub Actions 設定（Secrets、workflow 重點）
- auto_push-to-threads.py 使用說明（參數、環境變數）
- 常見問題與除錯（包含 changed_files 為空的解法）
- 本地測試 / 手動執行
- 注意事項

檔案清單（主要）
- .github/workflows/auto_push_to_threads.yml — GitHub Actions workflow，負責偵測 push、計算 changed files、呼叫腳本。
- auto_push-to-threads.py — 發送內容到 Threads 的主程式。

需求
- GitHub Actions runner: ubuntu-latest（已設定）。
- Python 3.11。
- Python 套件: requests, threads-sdk, pandas（workflow 會安裝）。
- 在 Actions Secrets 設定以下值（Repository → Settings → Secrets）:
  - THREADS_USER_ID
  - THREADS_ACCESS_TOKEN
  - THREADS_APP_SECRET

快速啟動
1. 把程式碼 push 到 main 分支（或建立 PR 並 merge）：
   - workflow on: push: branches: [ main ] 會啟動。
2. 檢查 Actions 執行紀錄，查看 step logs 與 debug 輸出。

GitHub Actions 設定重點
- Checkout：
  - 必須將 actions/checkout 的 fetch-depth 設為 0，否則 git diff-tree 或其他比對無法看到完整歷史。範例：
    with:
      fetch-depth: 0
- 取得 changed files：
  - workflow 內以 git diff-tree --no-commit-id --name-only -r HEAD 取得當前 commit 的檔案清單，將逐行輸出並轉為空白分隔字串傳給 python。
  - 由於使用的是 shell 展開，若檔名含空白會導致切分錯誤；若 repository 可能有空白檔名，請改用 JSON 或 environment 傳整段字串再在腳本中解析。
- 傳參數給 python：
  - commit message 用第一個引號包起來（避免空白問題）。
  - changed_files 以未加引號的方式傳，shell 會展開成多個 argv，使腳本內 sys.argv[2:] 接到每個檔名。

auto_push-to-threads.py 使用說明
- 參數（執行方式）：
  - python3 auto_push-to-threads.py "<commit message>" file1.py file2.py ...
  - 程式內會把 sys.argv[1] 當 commit_message，sys.argv[2:] 當 changed_files 列表。
- 環境變數（優先於 secret.json）：
  - THREADS_USER_ID
  - THREADS_ACCESS_TOKEN
  - THREADS_APP_SECRET
- 行為摘要：
  - 讀取 secrets（env 優先，否則讀 secret.json）。
  - 嘗試呼叫 refresh token endpoint（若從 secret.json 讀入並設定 persist=True，才會寫回檔案；CI 環境不會寫回）。
  - 依 changed_files 產生 GitHub 檔案 URL 清單並發成一或多個 Threads container。
- 測試模式：
  - 若 commit_message 前綴為 "-debug"，腳本會印出訊息並退出，不會發文。

常見問題與除錯
- 問題：printf '%s\n' "$FILES" 沒輸出（Files 為空）
  - 檢查 actions/checkout 是否有 fetch-depth: 0；沒有完整 fetch，HEAD 可能不是預期的 commit，git diff-tree 會找不到變更。
  - 檢查 workflow step 中的 debug 輸出：GITHUB_EVENT_PATH 的 payload（已在 step log 印出），git rev-parse --verify HEAD，git status，以及 git diff-tree 的逐行輸出。
  - 若 events payload 的 commits 為空（例如某些 API push 或 force push），不要只依賴 payload；改用 git diff-tree 或 git diff --name-only BEFORE AFTER（若取得 before/after SHA）。
- 問題：python 收到 changed_files 為 []
  - 確認 workflow run step 的 python3 執行行：python3 auto_push-to-threads.py "${{ steps.vars.outputs.commit_message }}" ${{ steps.vars.outputs.changed_files }}
    - 如果 steps.vars.outputs.changed_files 為空字串或含換行導致被解析為單一空值，shell 會傳入 0 或 1 個參數。
  - 建議在 workflow 的 run step 把 outputs 先放到 env 再傳（能更容易 debug）：
    env:
      COMMIT_MSG: ${{ steps.vars.outputs.commit_message }}
      CHANGED_FILES: ${{ steps.vars.outputs.changed_files }}
    run: |
      echo "Commit message: $COMMIT_MSG"
      echo "Changed files raw: '$CHANGED_FILES'"
      python3 auto_push-to-threads.py "$COMMIT_MSG" $CHANGED_FILES
  - 在 vars step 裡已包含大量 debug echo，查看該 step log 判斷 FILES 變數為何為空。
- 檢查點（建議）：
  - Actions run logs → open "Determine commit message and changed files" step → 貼出 "=== event payload ===" 與 "DEBUG: git diff-tree output" 的部分供分析。
  - 可以在 workflow 裡把 FILES 輸出到檔案作為測試： printf '%s\n' "$FILES" > /tmp/changed_files.txt 然後在下一 step cat 試看。

本地測試 / 手動執行
- 如果要在本機測試：
  - 建議先在本機設好 secret.json（內容包含 user_id、access_token、app_secret），或以 env export：
    export THREADS_USER_ID=...
    export THREADS_ACCESS_TOKEN=...
    export THREADS_APP_SECRET=...
  - 在 repository 目錄執行：
    python3 auto_push-to-threads.py "測試 commit 訊息" path/to/file1.py path/to/file2.py
  - 注意：在 local 執行會呼叫互聯網的 API（refresh token、publish）；若需要 dry-run，可在程式中利用 -debug 前綴或暫時把 network 調用註解。

注意事項
- 憑證安全：不要把 secret.json 上傳到遠端 public repo。CI 使用 Actions Secrets（recommended）。
- 檔名含空白：目前 workflow 以空白分隔檔名，若 repository 中可能有空白檔名，請改用 JSON 或把 changed files 放到 env 中整段傳遞並在腳本裡解析。
- Rate limits / API 失敗：Threads / Meta API 可能有速率限制或權杖過期，腳本已包含 refresh_token 邏輯但仍需捕捉錯誤並重試或 log。

若需要我：
- 幫你把 README 補上更詳細的 debug 範例 log（貼出你執行的 step log）；
- 或直接修改 workflow（例如把 changed_files 改成 JSON 傳遞或把 outputs 先寫入 env）以確保 Python 能正確接收檔案列表。
