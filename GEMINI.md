# MudScript: Project Instructions & Architecture

Welcome to the MudScript codebase. This document outlines the project structure, architectural patterns, and development workflows for this Go-based MUD (Multi-User Dungeon) engine.

## 🌟 Project Overview
MudScript is a high-performance MUD engine that combines a Go-based driver with an LPC-like scripting language for game content. It features a modern web interface (WebSocket/WebRTC) and a hybrid filesystem for easy distribution and development.

## 🏗️ Core Architecture

### 1. The Go Driver (`/driver`)
- **Role**: The engine's heart. Manages networking, heartbeats, object lifecycle, and provides "Efuns" (External Functions) to the scripting layer.
- **Efuns**: Go functions exposed to LPC scripts (e.g., `write`, `say`, `move_object`). Defined in `driver/efun.go`.
- **Concurrency**: Thread-safe environment management and non-blocking I/O.

### 2. The Streamlined LPC Interpreter (`/lexer`, `/parser`, `/evaluator`, `/ast`, `/object`)
- **Lexer**: Tokenizes LPC script files (ANSI C based).
- **Parser**: Builds an Abstract Syntax Tree (AST) focused strictly on LPC structures.
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
