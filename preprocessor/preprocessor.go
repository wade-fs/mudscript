// preprocessor/preprocessor.go

package preprocessor

import (
	"bufio"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strconv"
	"strings"
)

type Preprocessor struct {
	MudLibPath string
	Macros     map[string]string
}

func New(mudLibPath string) *Preprocessor {
	return &Preprocessor{
		MudLibPath: mudLibPath,
		Macros:     make(map[string]string),
	}
}

// 用來追蹤 if/elif/else 狀態的結構
type condState struct {
	isSkipping bool // 目前這個區塊是否正在被跳過
	hasMatched bool // 這個 if/elif 鏈中，是否已經有任何一個條件成立過？
}

func (p *Preprocessor) Process(filename, input string) (string, error) {
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
		trimmed := strings.TrimSpace(line)

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

		// 如果目前在忽略區塊內，直接塞入空行 (保留行號)
		if isSkipping() {
			output.WriteString("\n")
			continue
		}

		// ==========================================
		// 2. 處理巨集定義 (#define)
		// ==========================================
		if strings.HasPrefix(trimmed, "#define ") {
			parts := strings.Fields(trimmed[8:])
			if len(parts) > 0 {
				key := parts[0]
				val := ""
				if len(parts) > 1 {
					idx := strings.Index(trimmed, key) + len(key)
					val = strings.TrimSpace(trimmed[idx:])
				}
				p.Macros[key] = val
			}
			output.WriteString("\n")
			continue
		}

		// ==========================================
		// 3. 處理檔案引入 (#include)
		// ==========================================
		if strings.HasPrefix(trimmed, "#include ") {
			pathStr := strings.TrimSpace(trimmed[9:])
			pathStr = strings.Trim(pathStr, "\"<>")

			var fullPath string
			if strings.HasPrefix(pathStr, "/") {
				fullPath = filepath.Join(p.MudLibPath, pathStr)
			} else {
				fullPath = filepath.Join(p.MudLibPath, filepath.Dir(filename), pathStr)
			}

			content, err := os.ReadFile(fullPath)
			if err != nil {
				return "", fmt.Errorf("前處理器錯誤: 找不到引入的檔案 %s (%v)", pathStr, err)
			}

			includedContent, err := p.Process(pathStr, string(content))
			if err != nil {
				return "", err
			}
			output.WriteString(includedContent + "\n")
			continue
		}

		// ==========================================
		// 4. 處理一般程式碼：替換巨集
		// ==========================================
		outLine := line
		if len(p.Macros) > 0 {
			for k, v := range p.Macros {
				re := regexp.MustCompile(`\b` + regexp.QuoteMeta(k) + `\b`)
				outLine = re.ReplaceAllString(outLine, v)
			}
		}

		output.WriteString(outLine + "\n")
	}

	return output.String(), nil
}

// evalCondition 評估前處理器的邏輯判斷 (例如 "ENABLE_CRIT == 1")
func (p *Preprocessor) evalCondition(condStr string) bool {
	// 1. 先把條件式裡面的巨集替換為真實的數值字串
	for k, v := range p.Macros {
		// 使用 \b 確保只替換獨立的單字
		re := regexp.MustCompile(`\b` + regexp.QuoteMeta(k) + `\b`)
		// 如果巨集沒有值 (例如 #define MODE_A)，預設替換為 "1"
		replaceVal := v
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
