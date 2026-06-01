// preprocessor/preprocessor.go

package preprocessor

import (
	"bufio"
	"fmt"
	"io/fs"
	"os"
	"path/filepath"
	"regexp"
	"strconv"
	"strings"
)

type Macro struct {
	Name string
	Args []string
	Body string
}

type Preprocessor struct {
	MudLibPath    string
	Macros        map[string]Macro
	EmbeddedFS    fs.FS  // 🚀 新增：支援嵌入式檔案系統
	GlobalInclude string // 🚀 新增：全域自動引入標頭檔
}

func New(mudLibPath string) *Preprocessor {
	return &Preprocessor{
		MudLibPath: mudLibPath,
		Macros:     make(map[string]Macro),
	}
}

// SetEmbeddedFS 設定嵌入式檔案系統
func (p *Preprocessor) SetEmbeddedFS(efs fs.FS) {
	p.EmbeddedFS = efs
}

// 用來追蹤 if/elif/else 狀態的結構
type condState struct {
	isSkipping bool // 目前這個區塊是否正在被跳過
	hasMatched bool // 這個 if/elif 鏈中，是否已經有任何一個條件成立過？
}

func (p *Preprocessor) Process(filename, input string) (string, error) {
	// 🚀 新增：全域自動引入處理 (避免無窮遞迴引入自己)
	if p.GlobalInclude != "" && filename != p.GlobalInclude && !strings.HasSuffix(filename, "/"+p.GlobalInclude) {
		input = "#include <" + p.GlobalInclude + ">\n" + input
	}

	var output strings.Builder
	scanner := bufio.NewScanner(strings.NewReader(input))
	
	var condStack []condState // 改用新的狀態 Stack

	// 判斷目前是否處於被忽略的區塊中 (只要有任何一層正在跳過，就全部跳過)
	isSkipping := func() bool {
		for _, state := range condStack {
			if state.isSkipping {
				return true
			}
		}
		return false
	}

	for scanner.Scan() {
		line := scanner.Text()
		
		// 🚩 先移除註解，但要避開字串內部的 // (如網址)
		// 使用 strings.Builder 與 WriteByte 確保不破壞 UTF-8 字節流
		var cleanLineBuilder strings.Builder
		inString := false
		for i := 0; i < len(line); i++ {
			if line[i] == '"' && (i == 0 || line[i-1] != '\\') {
				inString = !inString
			}
			if !inString && i < len(line)-1 && line[i] == '/' && line[i+1] == '/' {
				break // 遇到註解，本行後續捨棄
			}
			cleanLineBuilder.WriteByte(line[i])
		}
		cleanLine := cleanLineBuilder.String()
		trimmed := strings.TrimSpace(cleanLine)

		// ==========================================
		// 1. 處理條件編譯
		// ==========================================
		if strings.HasPrefix(trimmed, "#ifdef ") {
			macroName := strings.TrimSpace(trimmed[7:])
			_, exists := p.Macros[macroName]
			condStack = append(condStack, condState{
				isSkipping: !exists,
				hasMatched: exists,
			})
			output.WriteString("\n")
			continue
		} else if strings.HasPrefix(trimmed, "#ifndef ") {
			macroName := strings.TrimSpace(trimmed[8:])
			_, exists := p.Macros[macroName]
			condStack = append(condStack, condState{
				isSkipping: exists,
				hasMatched: !exists,
			})
			output.WriteString("\n")
			continue
		} else if strings.HasPrefix(trimmed, "#if ") { // [新增] 支援 #if 表達式
			condStr := strings.TrimSpace(trimmed[4:])
			isTrue := p.evalCondition(condStr)
			condStack = append(condStack, condState{
				isSkipping: !isTrue,
				hasMatched: isTrue,
			})
			output.WriteString("\n")
			continue
		} else if strings.HasPrefix(trimmed, "#elif ") { // [升級] 讓 #elif 也支援表達式
			if len(condStack) > 0 {
				condStr := strings.TrimSpace(trimmed[6:])
				top := &condStack[len(condStack)-1]

				if top.hasMatched {
					// 前面已經有條件成立過，這裡必須強制跳過
					top.isSkipping = true
				} else {
					// 前面沒有條件成立，評估這個 elif 的表達式
					isTrue := p.evalCondition(condStr)
					top.isSkipping = !isTrue
					if isTrue {
						top.hasMatched = true
					}
				}
			}
			output.WriteString("\n")
			continue
		} else if trimmed == "#else" {
			if len(condStack) > 0 {
				top := &condStack[len(condStack)-1]
				if top.hasMatched {
					// 前面已經有條件成立過，else 必須跳過
					top.isSkipping = true
				} else {
					// 前面都沒成立，執行 else 區塊
					top.isSkipping = false
					top.hasMatched = true 
				}
			}
			output.WriteString("\n")
			continue
		} else if trimmed == "#endif" {
			if len(condStack) > 0 {
				condStack = condStack[:len(condStack)-1] // 彈出最後一層
			}
			output.WriteString("\n")
			continue
		}

		// ==========================================
		// 2. 處理巨集定義 (#define)
		// ==========================================
		if strings.HasPrefix(trimmed, "#define ") {
			fullDefine := trimmed
			// 支援多行定義 (結尾帶有 \)
			for strings.HasSuffix(strings.TrimSpace(fullDefine), "\\") {
				fullDefine = strings.TrimSuffix(strings.TrimSpace(fullDefine), "\\")
				if scanner.Scan() {
					nextLine := scanner.Text()
					// 多行定義時也要清理每一行的註解
					var cleanNextBuilder strings.Builder
					inStrNext := false
					for j := 0; j < len(nextLine); j++ {
						if nextLine[j] == '"' && (j == 0 || nextLine[j-1] != '\\') {
							inStrNext = !inStrNext
						}
						if !inStrNext && j < len(nextLine)-1 && nextLine[j] == '/' && nextLine[j+1] == '/' {
							break
						}
						cleanNextBuilder.WriteByte(nextLine[j])
					}
					fullDefine += " " + strings.TrimSpace(cleanNextBuilder.String())
					output.WriteString("\n") // 補償行號
				} else {
					break
				}
			}

			defineBody := strings.TrimSpace(fullDefine[8:])
			if defineBody == "" {
				output.WriteString("\n")
				continue
			}

			var name string
			var args []string
			var body string

			// 檢查是否為函式型巨集: #define YELLOW(x) CLR_YEL + x + CLR_NOR
			if idx := strings.Index(defineBody, "("); idx > 0 && !strings.Contains(defineBody[:idx], " ") {
				name = defineBody[:idx]
				endIdx := strings.Index(defineBody, ")")
				if endIdx > idx {
					argStr := defineBody[idx+1 : endIdx]
					if argStr != "" {
						for _, s := range strings.Split(argStr, ",") {
							args = append(args, strings.TrimSpace(s))
						}
					}
					body = strings.TrimSpace(defineBody[endIdx+1:])
				} else {
					// 格式錯誤，退回一般巨集處理
					parts := strings.Fields(defineBody)
					name = parts[0]
					if len(parts) > 1 {
						body = strings.TrimSpace(defineBody[len(name):])
					}
				}
			} else {
				// 一般巨集: #define PI 3.14
				parts := strings.Fields(defineBody)
				name = parts[0]
				if len(parts) > 1 {
					body = strings.TrimSpace(defineBody[len(name):])
				}
			}

			p.Macros[name] = Macro{Name: name, Args: args, Body: body}
			output.WriteString("\n")
			continue
		}

		// 如果目前在忽略區塊內，直接塞入空行 (保留行號)
		if isSkipping() {
			output.WriteString("\n")
			continue
		}

		// ==========================================
		// 3. 處理檔案引入 (#include)
		// ==========================================
		if strings.HasPrefix(trimmed, "#include ") {
			pathStr := strings.TrimSpace(trimmed[9:])
			pathStr = strings.Trim(pathStr, "\"<>")

			var relPath string
			if strings.HasPrefix(pathStr, "/") {
				relPath = strings.TrimPrefix(pathStr, "/")
			} else {
				dir := filepath.Dir(filename)
				relPath = filepath.Join(dir, pathStr)
			}
			relPath = strings.TrimPrefix(relPath, "/")

			var content []byte
			var err error

			// 1. 優先嘗試從實體磁碟讀取
			fullPath := filepath.Join(p.MudLibPath, relPath)
			if _, statErr := os.Stat(fullPath); statErr == nil {
				content, err = os.ReadFile(fullPath)
			} else if p.EmbeddedFS != nil {
				// 2. 備備嘗試從嵌入檔案讀取
				embedPath := filepath.Join("mudlib", relPath)
				content, err = fs.ReadFile(p.EmbeddedFS, embedPath)
			} else {
				err = fmt.Errorf("找不到檔案: %s", pathStr)
			}

			if err != nil {
				return "", fmt.Errorf("前處理器錯誤: %v", err)
			}

			includedContent, err := p.Process(relPath, string(content))
			if err != nil {
				return "", err
			}
			output.WriteString(includedContent + "\n")
			continue
		}

		// ==========================================
		// 4. 處理一般程式碼：替換巨集
		// ==========================================
		outLine := cleanLine
		if len(p.Macros) > 0 {
			// 先處理函式型巨集
			for name, m := range p.Macros {
				if len(m.Args) > 0 {
					searchIdx := 0
					for {
						idx := strings.Index(outLine[searchIdx:], name)
						if idx == -1 { break }
						idx += searchIdx
						
						// 檢查是否為獨立單字
						isWord := true
						if idx > 0 && isAlphaNumeric(outLine[idx-1]) { isWord = false }
						if idx+len(name) < len(outLine) && isAlphaNumeric(outLine[idx+len(name)]) { isWord = false }
						
						if !isWord {
							searchIdx = idx + 1
							continue
						}

						// 尋找 '('
						rest := outLine[idx+len(name):]
						lparenIdx := strings.Index(rest, "(")
						if lparenIdx == -1 || strings.TrimSpace(rest[:lparenIdx]) != "" {
							searchIdx = idx + 1
							continue
						}
						
						// 尋找成對的 ')' (支援巢狀括號)
						start := idx + len(name) + lparenIdx + 1
						depth := 1
						rparenIdx := -1
						for i := start; i < len(outLine); i++ {
							if outLine[i] == '(' { depth++ } else if outLine[i] == ')' {
								depth--
								if depth == 0 {
									rparenIdx = i
									break
								}
							}
						}

						if rparenIdx == -1 {
							searchIdx = idx + 1
							continue
						}

						// 提取參數並拆分 (考慮到參數內可能也有逗號，如函數呼叫)
						argStr := outLine[start:rparenIdx]
						providedArgs := splitMacroArgs(argStr)
						
						if len(providedArgs) != len(m.Args) {
							searchIdx = rparenIdx + 1
							continue
						}

						// 執行替換
						finalBody := m.Body
						for i, argName := range m.Args {
							val := strings.TrimSpace(providedArgs[i])
							argRe := regexp.MustCompile(`\b` + regexp.QuoteMeta(argName) + `\b`)
							finalBody = argRe.ReplaceAllString(finalBody, val)
						}
						
						// 組裝回原字串
						outLine = outLine[:idx] + finalBody + outLine[rparenIdx+1:]
						searchIdx = idx + len(finalBody)
					}
				}
			}

			// 再處理一般巨集
			for name, m := range p.Macros {
				if len(m.Args) == 0 {
					re := regexp.MustCompile(`\b` + regexp.QuoteMeta(name) + `\b`)
					outLine = re.ReplaceAllString(outLine, m.Body)
				}
			}
		}

		output.WriteString(outLine + "\n")
	}

	return output.String(), nil
}

func isAlphaNumeric(c byte) bool {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_'
}

func splitMacroArgs(s string) []string {
	var args []string
	var current strings.Builder
	parenDepth := 0
	braceDepth := 0
	bracketDepth := 0
	inString := false
	for i := 0; i < len(s); i++ {
		c := s[i]
		if c == '"' && (i == 0 || s[i-1] != '\\') {
			inString = !inString
		}
		if !inString {
			if c == '(' { parenDepth++ } else if c == ')' { parenDepth-- } else if c == '{' { braceDepth++ } else if c == '}' { braceDepth-- } else if c == '[' { bracketDepth++ } else if c == ']' { bracketDepth-- } else if c == ',' && parenDepth == 0 && braceDepth == 0 && bracketDepth == 0 {
				args = append(args, current.String())
				current.Reset()
				continue
			}
		}
		current.WriteByte(c)
	}
	args = append(args, current.String())
	return args
}

// evalCondition 評估前處理器的邏輯判斷 (例如 "ENABLE_CRIT == 1")
func (p *Preprocessor) evalCondition(condStr string) bool {
	// 1. 先把條件式裡面的巨集替換為真實的數值字串
	for k, v := range p.Macros {
		// 使用 \b 確保只替換獨立的單字
		re := regexp.MustCompile(`\b` + regexp.QuoteMeta(k) + `\b`)
		// 如果巨集沒有值 (例如 #define MODE_A)，預設替換為 "1"
		replaceVal := v.Body
		if replaceVal == "" {
			replaceVal = "1"
		}
		condStr = re.ReplaceAllString(condStr, replaceVal)
	}

	condStr = strings.TrimSpace(condStr)

	// 如果替換後只剩下一個數字 (例如 "#if 1")
	if val, err := strconv.Atoi(condStr); err == nil {
		return val != 0
	}

	// 2. 尋找並拆解比較運算子
	operators := []string{"==", "!=", ">=", "<=", ">", "<"}
	var op string
	var parts []string

	for _, o := range operators {
		if strings.Contains(condStr, o) {
			op = o
			parts = strings.Split(condStr, o)
			break
		}
	}

	// 如果沒有合法的運算子，預設回傳 false
	if len(parts) != 2 {
		return false
	}

	leftStr := strings.TrimSpace(parts[0])
	rightStr := strings.TrimSpace(parts[1])

	// 3. 嘗試轉為整數進行比較
	leftVal, err1 := strconv.Atoi(leftStr)
	rightVal, err2 := strconv.Atoi(rightStr)

	// 如果不是數字 (可能是未定義的巨集，被當作字串 0)
	if err1 != nil { leftVal = 0 }
	if err2 != nil { rightVal = 0 }

	switch op {
	case "==": return leftVal == rightVal
	case "!=": return leftVal != rightVal
	case ">":  return leftVal > rightVal
	case "<":  return leftVal < rightVal
	case ">=": return leftVal >= rightVal
	case "<=": return leftVal <= rightVal
	}

	return false
}
