//go:build fsmud
// +build fsmud

package mudscript

import "embed"

// 🚀 專供給 bin/fsmud 使用的資源
//go:embed all:fsmud
var Assets embed.FS
