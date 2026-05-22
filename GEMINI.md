# MudScript: Project Instructions & Architecture

Welcome to the MudScript codebase. This document outlines the project structure, architectural patterns, and development workflows for this Go-based MUD (Multi-User Dungeon) engine.

## 🌟 Project Overview
MudScript is a high-performance MUD engine that combines a Go-based driver with an LPC-like scripting language for game content. It features a modern web interface (WebSocket/WebRTC) and a hybrid filesystem for easy distribution and development.

## 🏗️ Core Architecture

### 1. The Go Driver (`/driver`)
- **Role**: The engine's heart. Manages networking, heartbeats, object lifecycle, and provides "Efuns" (External Functions) to the scripting layer.
- **Efuns**: Go functions exposed to LPC scripts (e.g., `write`, `say`, `move_object`). Defined in `driver/efun.go`.
- **Concurrency**: Thread-safe environment management and non-blocking I/O.

### 2. The Interpreter (`/lexer`, `/parser`, `/evaluator`, `/ast`, `/object`)
- **Lexer**: Tokenizes LPC-like script files.
- **Parser**: Builds an Abstract Syntax Tree (AST).
- **Evaluator**: A tree-walking interpreter that executes the AST.
- **Object System**: Defines runtime types (Integer, String, Array, Mapping, Object, etc.) in `/object`.

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

### Build Commands
- **Linux**: `make fsmud` (binary in `bin/fsmud`)
- **Windows**: `make fsmud.exe` (binary in `bin/fsmud.exe`)
- **Cleanup**: `make clean`

### Scripting Conventions
- **Inheritance**: LPC scripts use the `inherit` keyword to extend base classes.
- **Preprocessors**: Supports standard macros and parameter-based macros.
- **Hot Reload**: The engine supports reloading scripts without restarting the Go process (managed by `cmd_update.c` in mudlib).

## 📏 Coding Standards

### Go Code
- Follow idiomatic Go (Effective Go).
- Use `sync.Mutex` for protecting shared state in the driver.
- Ensure all new Efuns are documented in `docs/README-efuns.md`.

### LPC Scripts
- Keep scripts modular. Prefer inheritance over large, monolithic files.
- Use `ansi.h` for color codes.
- Follow the directory structure: NPCs in `/npc`, items in `/item`, etc.

## 🔍 Key Files
- `driver/driver.go`: Main driver loop and object management.
- `evaluator/evaluator.go`: The core execution logic.
- `mudlib/master.c`: The master object that controls security and startup.
- `mudlib/std/object.c`: The root base class for all LPC objects.

## 📚 Documentation
- [Efuns Reference](docs/README-efuns.md)
- [Interpreter Details](docs/README-monkey-interpreter.md)
- [TODO List](docs/README-TODO.md)
