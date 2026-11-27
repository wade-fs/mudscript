// driver/file.go
package driver

import (
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"strings"
)

func (d *Driver) NormalizePath(path string) string {
	cleanPath := filepath.Clean(path)
	if cleanPath == "." || cleanPath == "/" {
		return ""
	}
	cleanPath = filepath.ToSlash(cleanPath)
	if !strings.HasPrefix(cleanPath, "/") {
		cleanPath = "/" + cleanPath
	}
	return cleanPath
}

// 🚀 新增：路徑解析 (支援 ./ 與 ../，以及跨服沙盒自動映射)
func (d *Driver) ResolvePath(basePath, relPath string) string {
	// 1. 處理相對路徑
	if strings.HasPrefix(relPath, ".") {
		dir := filepath.Dir(basePath)
		resolved := filepath.Join(dir, relPath)
		res := filepath.ToSlash(resolved)
		if !strings.HasPrefix(res, "/") {
			res = "/" + res
		}
		return res
	}

	// 2. 處理絕對路徑 (關鍵：跨服沙盒自動重導向)
	// 如果發起呼叫的物件 (basePath) 位於遠端緩存目錄中
	// 例如：/data/fs_cache/fantasy.space/area/newbie/room_0_0.c
	if strings.HasPrefix(basePath, "/data/fs_cache/") {
		// 提取 mudlib_id
		parts := strings.Split(strings.TrimPrefix(basePath, "/data/fs_cache/"), "/")
		if len(parts) > 0 {
			mudlibID := parts[0]
			sandboxPrefix := "/data/fs_cache/" + mudlibID

			// 如果目標路徑是以 / 開頭的絕對路徑，且不在「全域白名單」中
			if strings.HasPrefix(relPath, "/") {
				// 白名單：不需要重導向的目錄
				if !strings.HasPrefix(relPath, "/std/") &&
					!strings.HasPrefix(relPath, "/secure/") &&
					!strings.HasPrefix(relPath, "/include/") &&
					!strings.HasPrefix(relPath, "/cmds/") &&
					!strings.HasPrefix(relPath, "/data/fs_cache/") {

					// 自動加上沙盒前綴
					// 例如：/area/newbie/... -> /data/fs_cache/fantasy.space/area/newbie/...
					return sandboxPrefix + relPath
				}
			}
		}
	}

	// 3. 一般絕對路徑處理
	if !strings.HasPrefix(relPath, "/") {
		return "/" + relPath
	}
	return relPath
}

// IsWithinBase 檢查 targetPath 是否安全位於 baseDir 之內（防禦 .. 逃逸與前綴偽造）
func isWithinBase(baseDir, targetPath string) bool {
	cleanBase := filepath.Clean(baseDir)
	cleanTarget := filepath.Clean(targetPath)
	rel, err := filepath.Rel(cleanBase, cleanTarget)
	if err != nil {
		return false
	}
	return rel != ".." && !strings.HasPrefix(rel, ".."+string(filepath.Separator))
}

// ReadLayers 回傳依優先順序排列的磁碟讀取層：上層 MudLibPath 優先，其次 CommonPath
func (d *Driver) ReadLayers() []string {
	layers := []string{d.Config.MudLibPath}
	if d.Config.CommonPath != "" && filepath.Clean(d.Config.CommonPath) != filepath.Clean(d.Config.MudLibPath) {
		layers = append(layers, d.Config.CommonPath)
	}
	return layers
}

// ResolveWritePath 將虛擬路徑解析為上層 MudLibPath 內的實體寫入路徑，嚴格禁止寫入 CommonPath 或逃出 Chroot
func (d *Driver) ResolveWritePath(virtualPath string) (string, error) {
	relPath := strings.TrimPrefix(d.NormalizePath(virtualPath), "/")
	fullPath := filepath.Join(d.Config.MudLibPath, relPath)
	if !isWithinBase(d.Config.MudLibPath, fullPath) {
		return "", fmt.Errorf("chroot violation: %s", virtualPath)
	}
	return fullPath, nil
}

// ResolveReadPath 依 MudLibPath -> CommonPath 順序尋找磁碟中存在的檔案或目錄
func (d *Driver) ResolveReadPath(virtualPath string) (string, bool, error) {
	relPath := strings.TrimPrefix(d.NormalizePath(virtualPath), "/")
	for i, layer := range d.ReadLayers() {
		fullPath := filepath.Join(layer, relPath)
		if !isWithinBase(layer, fullPath) {
			return "", false, fmt.Errorf("chroot violation: %s", virtualPath)
		}
		if _, err := os.Stat(fullPath); err == nil {
			return fullPath, i > 0, nil
		}
	}
	return "", false, fmt.Errorf("file not found: %s", virtualPath)
}

// ReadExactFile 讀取精確路徑的檔案（不自動補 .c），支援 MudLibPath -> CommonPath -> EmbeddedFS
func (d *Driver) ReadExactFile(filename string) ([]byte, error) {
	relPath := strings.TrimPrefix(d.NormalizePath(filename), "/")
	if relPath == "" {
		return nil, fmt.Errorf("file not found: %s", filename)
	}

	for _, layer := range d.ReadLayers() {
		fullPath := filepath.Join(layer, relPath)
		if !isWithinBase(layer, fullPath) {
			return nil, fmt.Errorf("chroot violation: %s", filename)
		}
		if info, err := os.Stat(fullPath); err == nil && !info.IsDir() {
			return os.ReadFile(fullPath)
		}
	}

	if d.Config.EmbeddedFS != nil {
		for _, layer := range d.ReadLayers() {
			embedPath := strings.TrimPrefix(filepath.ToSlash(filepath.Join(layer, relPath)), "/")
			if content, err := fs.ReadFile(d.Config.EmbeddedFS, embedPath); err == nil {
				return content, nil
			}
		}
	}

	return nil, fmt.Errorf("file not found: %s", filename)
}

// StatOverlay 查詢檔案或目錄資訊（依 MudLibPath -> CommonPath -> EmbeddedFS 順序）
func (d *Driver) StatOverlay(filename string) (fs.FileInfo, error) {
	relPath := strings.TrimPrefix(d.NormalizePath(filename), "/")
	for _, layer := range d.ReadLayers() {
		fullPath := filepath.Join(layer, relPath)
		if !isWithinBase(layer, fullPath) {
			return nil, fmt.Errorf("chroot violation: %s", filename)
		}
		if info, err := os.Stat(fullPath); err == nil {
			return info, nil
		}
	}

	if d.Config.EmbeddedFS != nil {
		for _, layer := range d.ReadLayers() {
			embedPath := strings.TrimPrefix(filepath.ToSlash(filepath.Join(layer, relPath)), "/")
			if info, err := fs.Stat(d.Config.EmbeddedFS, embedPath); err == nil {
				return info, nil
			}
		}
	}

	return nil, fmt.Errorf("file not found: %s", filename)
}

// 🚀 新增：混合模式讀取檔案 (支援 .c 尾碼自動修復與多層 Overlay VFS)
func (d *Driver) ReadFile(filename string) ([]byte, error) {
	tryFiles := []string{filename}
	if !strings.HasSuffix(filename, ".c") {
		tryFiles = append(tryFiles, filename+".c")
	}

	for _, f := range tryFiles {
		if content, err := d.ReadExactFile(f); err == nil {
			return content, nil
		} else if strings.Contains(err.Error(), "chroot violation") {
			return nil, err
		}
	}

	return nil, fmt.Errorf("file not found: %s", filename)
}

func (d *Driver) DiscoverMasterFile() string {
	content, err := d.ReadFile("/include/config.h")
	if err != nil {
		return "/master.c"
	}
	lines := strings.Split(string(content), "\n")
	for _, line := range lines {
		if strings.Contains(line, "#define MASTER_FILE") {
			parts := strings.Fields(line)
			if len(parts) >= 3 {
				path := strings.Trim(parts[2], "\"")
				return path
			}
		}
	}
	return "/master.c"
}

func (d *Driver) formatParserErrors(filename string, errors []string) error {
	var sb strings.Builder
	sb.WriteString(fmt.Sprintf("❌ 語法錯誤 in %s\n\n", filename))
	for i, err := range errors {
		sb.WriteString(fmt.Sprintf("   %2d. %s\n", i+1, err))
	}
	return fmt.Errorf("%s", sb.String())
}
