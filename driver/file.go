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
	if strings.HasPrefix(basePath, "/data/fs_cache/") {
		parts := strings.Split(strings.TrimPrefix(basePath, "/data/fs_cache/"), "/")
		if len(parts) > 0 {
			mudlibID := parts[0]
			sandboxPrefix := "/data/fs_cache/" + mudlibID
			if strings.HasPrefix(relPath, "/") {
				if !strings.HasPrefix(relPath, "/std/") &&
					!strings.HasPrefix(relPath, "/secure/") &&
					!strings.HasPrefix(relPath, "/include/") &&
					!strings.HasPrefix(relPath, "/cmds/") &&
					!strings.HasPrefix(relPath, "/data/fs_cache/") {
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

// 🚀 新增：混合模式讀取檔案 (支援 .c 尾碼自動修復)
func (d *Driver) ReadFile(filename string) ([]byte, error) {
	tryFiles := []string{filename}
	if !strings.HasSuffix(filename, ".c") {
		tryFiles = append(tryFiles, filename+".c")
	}

	for _, f := range tryFiles {
		relPath := strings.TrimPrefix(f, "/")
		fullPath := filepath.Join(d.Config.MudLibPath, relPath)
		cleanMudLib := filepath.Clean(d.Config.MudLibPath)
		cleanFull := filepath.Clean(fullPath)
		if !strings.HasPrefix(cleanFull, cleanMudLib) {
			return nil, fmt.Errorf("chroot violation: %s", f)
		}

		if _, err := os.Stat(fullPath); err == nil {
			return os.ReadFile(fullPath)
		}

		if d.Config.EmbeddedFS != nil {
			embedPath := filepath.Join(d.Config.MudLibPath, relPath)
			embedPath = filepath.ToSlash(embedPath)
			embedPath = strings.TrimPrefix(embedPath, "/")
			if content, err := fs.ReadFile(d.Config.EmbeddedFS, embedPath); err == nil {
				return content, nil
			}
		}
	}

	return nil, fmt.Errorf("file not found: %s", filename)
}

// 🚀 新增：寫入檔案 (支援 Virtual Chroot)
func (d *Driver) WriteFile(filename string, content []byte) error {
	relPath := strings.TrimPrefix(filename, "/")
	fullPath := filepath.Join(d.Config.MudLibPath, relPath)
	
	cleanMudLib := filepath.Clean(d.Config.MudLibPath)
	cleanFull := filepath.Clean(fullPath)
	if !strings.HasPrefix(cleanFull, cleanMudLib) {
		return fmt.Errorf("chroot violation: %s", filename)
	}

	// 確保父目錄存在
	os.MkdirAll(filepath.Dir(fullPath), 0755)

	return os.WriteFile(fullPath, content, 0644)
}

func (d *Driver) DiscoverMasterFile() string {
	configPath := filepath.Join(d.Config.MudLibPath, "include/config.h")
	content, err := os.ReadFile(configPath)
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

// 🚀 新增：掃描目錄檔案 (get_dir)
func (d *Driver) GetDir(path string) ([]string, error) {
	resolvedPath := d.ResolvePath("", path)
	
	// 處理萬用字元 (如 /data/*.o)
	if strings.Contains(resolvedPath, "*") {
		fullPattern := filepath.Join(d.Config.MudLibPath, resolvedPath)
		matches, err := filepath.Glob(fullPattern)
		if err != nil { return nil, err }
		
		var results []string
		for _, m := range matches {
			results = append(results, filepath.Base(m))
		}
		return results, nil
	}

	fullPath := filepath.Join(d.Config.MudLibPath, resolvedPath)
	
	// 🚀 關鍵修正：判斷目標是否為檔案而非目錄
	info, err := os.Stat(fullPath)
	if err != nil { return nil, err }
	
	if !info.IsDir() {
		return []string{filepath.Base(fullPath)}, nil
	}

	files, err := os.ReadDir(fullPath)
	if err != nil { return nil, err }

	var results []string
	for _, f := range files {
		name := f.Name()
		if f.IsDir() { name += "/" }
		results = append(results, name)
	}
	return results, nil
}
