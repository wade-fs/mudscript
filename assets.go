package mudscript

import "embed"

// 🚀 嵌入所有遊戲資源與網頁資源
//go:embed all:mudlib all:web/static
var Assets embed.FS
