# MudScript: Project Instructions & Architecture

Welcome to the MudScript codebase. This document outlines the project structure, architectural patterns, and development workflows for this Go-based MUD (Multi-User Dungeon) engine.

## 🌟 Project Overview
MudScript is a high-performance MUD engine that combines a Go-based driver with an LPC-like scripting language for game content. It features a modern web interface (WebSocket/WebRTC) and a hybrid filesystem for easy distribution and development.

## 🏗️ Core Architecture

### 1. The Go Driver (`/driver`)
- **Role**: The engine's heart. Manages networking, heartbeats, object lifecycle, and provides "Efuns" (External Functions) to the scripting layer.
- **Efuns**: Go functions exposed to LPC scripts (e.g., `write`, `say`, `move_object`). Defined in `driver/efun.go`.
- **Smart Sandboxing**: The Driver's `ResolvePath` automatically redirects absolute paths (e.g., `/area/`) to a remote world's cache if the calling object is from another Mudlib, ensuring complete isolation.
- **Extension Agnostic**: All file Efuns (load, clone, inherit) automatically handle the `.c` extension, making it optional for developers.
- **Concurrency**: Thread-safe environment management and non-blocking I/O.

### 2. The Streamlined LPC Interpreter (`/lexer`, `/parser`, `/evaluator`, `/ast`, `/object`)
- **Lexer**: Tokenizes LPC script files (ANSI C based).
- **Parser**: Builds an Abstract Syntax Tree (AST) focused strictly on LPC structures.
    - **Syntax Flexibility**: Supports single-statement control structures (`if`, `for`, `while`, `foreach`) without requiring braces `{}`.
- **Evaluator**: A tree-walking interpreter optimized for LPC execution patterns.
- **Object System**: Defines LPC runtime types: Integer, String, Array `({ })`, Mapping `([ ])`, LPCObject, and Closures `(: :)`.
- **Note**: All legacy elements (e.g., `let`, `fn`, `macro` keywords, and `[]` array style) have been removed to ensure a lean, standard-compliant core.

### 3. The Mudlib (`/mudlib`)
- **Role**: Contains all game logic (Rooms, NPCs, Items, Commands).
- **Language**: LPC-like syntax.
- **Hierarchy**:
    - `std/`: Base classes (inheritables like `room.c`, `npc.c`).
    - `secure/`: Security and master object logic.
    - `include/`: Header files (`.h`).
    - `area/`, `npc/`, `item/`: Game content.

### 4. Web Frontend (`/web/static`)
- **Role**: A Vanilla JS client that connects via WebSocket.
- **Features**: ANSI color support, clickable NPC IDs, and dynamic UI updates.

## 🛠️ Development Workflows

### Build & Test Commands
- **Build Linux**: `make fsmud` (binary in `bin/fsmud`)
- **Build Windows**: `make fsmud.exe` (binary in `bin/fsmud.exe`)
- **Run Tests**: `make test` (Runs automated LPC core verification)
- **Start Server**: `make run` (Starts the server in normal mode)
- **Cleanup**: `make clean`

### Scripting Conventions
- **Inheritance**: LPC scripts use the `inherit` keyword to extend base classes.
- **Preprocessors**: Supports standard macros and parameter-based macros.
- **Hot Reload**: The engine supports reloading scripts without restarting the Go process (managed by `cmd_update.c` in mudlib).

## 📏 Coding Standards

### 🛡️ System Integrity & Testing
- **Mandatory Testing**: ALWAYS run `make test` after any code change or update to ensure system stability and verify that no regressions were introduced.
- **Holistic Consistency**: Avoid "bandage fixes" (patching only one instance while leaving others inconsistent). Prioritize architectural cleanliness and project-wide uniformity.

### 📜 LPC Scripts
- **Modular Design**: Keep scripts modular. Prefer inheritance over large, monolithic files.
- **Color Codes**: Use `ansi.h` and the `{r}` tag system for all colorized output.
- **Internationalization (i18n)**: 
    - If a change is related to language or localization, it MUST be applied comprehensively across ALL affected rooms, objects, commands, and NPCs.
    - Use `select_lang()` and `_t()` for all player-facing strings.
- **Command Consistency**: 
    - If a change affects command handling or base functionality, it MUST be updated in all relevant command files in `/cmds`.
- **Directory Structure**: NPCs in `/npc`, items in `/item`, rooms in `/area`, etc.

### 🐹 Go Code
- Follow idiomatic Go (Effective Go).
- Use `sync.Mutex` for protecting shared state in the driver.
- Ensure all new Efuns are documented in `docs/README-efuns.md`.

## 🔍 Key Files
- `driver/driver.go`: Main driver loop and object management.
- `evaluator/evaluator.go`: The core execution logic.
- `mudlib/master.c`: The master object that controls security and startup.
- `mudlib/std/object.c`: The root base class for all LPC objects.

## 📚 Documentation
- [Efuns Reference](docs/README-efuns.md)
- [Interpreter Details](docs/README-monkey-interpreter.md)
- [TODO List](docs/README-TODO.md)

# target:

目前 ssh-like 的通訊有初步成功，但是當本機 fsgoto fantasy.space 之後，似乎之後的命令又變成本機(local)

## 我再說一次目前測試架構:
- 同樣的 Repo 我在本機開發，也會利用 "make push" 推到 hf, 讓它自動編譯並執行成為 hub
- 在 hub 主要當成 sshd-like, 同時它也會執行同一份 mudlib, 
- 在本機，想像成是其他朋友 clone 後，他會修改 mudlib, 因此要把本機當成是第三者，
- hub 的 mudlib_id 固化為 fantasy.space, mudlib_name 固化為 "fantasy space", 其他人，包括本機本身不能使用這個 mudlib_id, mudlib_name, 這一點要保證由 hub 統一認證，也就是就算是我從本機也不能命名為 mudlib_id : fantasy.space, mudlib_name : "狂想空間II"
- hub 的 god: "wade", 也就是識別為 wade@fantasy.space

## 那麼接下來說明測試狀況：

- 測試時，本機我會將 mudlib_id : fs.mud, mudlib_name: 測試空間(目前第一個角色登入時創建時只問一項)
- 所以理論上有三個角色：hub, mudlib=fantasy.space, mudlib=fs.mud。 hub 擔當 兩個不同 mudlib 的中間轉換角色。
- 當我從本機 也建立一個 wade, 但是識別為 wade@fs.mud, fsgoto fantasy.space 之後，感覺第一個房間是來自 hub, 但是之後的走動，卻又回到本機。應該是:
- 當 fsgoto 之後，所有命令應該由 hub 傳給 fantasy.space 這個  mud 解釋(執行)，fantasy.space 解釋再傳回 fs.mud
