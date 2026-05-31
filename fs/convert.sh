#!/bin/bash

# 定義錯誤紀錄檔的絕對路徑（避免切換目錄時找不到）
LOG_FILE="$(pwd)/convert_failed.log"

# 如果之前有舊的 log 檔，先清空
> "$LOG_FILE"

echo "開始進行全目錄（含子目錄）轉換作業..."

# 使用 find 找出目前目錄及所有子目錄下的「檔案」
# 排除這個腳本本身以及 log 檔
find . -type f ! -name "convert_all.sh" ! -name "convert_failed.log" | while read -r file; do
    
    echo "正在處理: $file"
    
    # 1. 先將原檔案更名為備份檔 (.bak)
    mv "$file" "$file.bak"
    
    # 2. 執行 iconv 轉碼
    iconv -f BIG5 -t UTF-8 "$file.bak" -o "$file" 2>/dev/null
    
    # 3. 檢查 iconv 是否成功
    if [ $? -eq 0 ]; then
        # 成功：刪除該檔案的備份檔
        rm "$file.bak"
    else
        # 失敗：將該檔案還原，並寫入 log
        mv "$file.bak" "$file"
        echo "$file" >> "$LOG_FILE"
        echo "  ❌ [失敗] $file (已還原)"
    fi

done

echo "--------------------------------"
if [ -s "$LOG_FILE" ]; then
    echo "作業完成，但有部分檔案轉換失敗。"
    echo "失敗清單已記錄至：$LOG_FILE"
else
    echo "恭喜！所有子目錄下的檔案皆轉換成功！"
    rm -f "$LOG_FILE" # 若無失敗則移除空的 log 檔
fi
