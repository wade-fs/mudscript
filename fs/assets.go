package fs
// 本檔案只有在編譯執行檔時才用得到，客製化 mudlib(本目錄) 時可以刪掉

import "embed"

// 🚀 專供給 bin/fs 使用的資源 (僅包含 legacy fs)
//go:embed all:*
var Assets embed.FS
