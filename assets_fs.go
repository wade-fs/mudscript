//go:build fs
// +build fs

package mudscript

import "embed"

// 🚀 專供給 bin/fs 使用的資源
//go:embed all:fs
var Assets embed.FS
