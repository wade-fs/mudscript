---
title: FSMUD Hub
emoji: 🌌
colorFrom: indigo
colorTo: blue
sdk: docker
pinned: false
---

# MudScript: Fantasy Space MUD Engine

[English] | [正體中文](README.zh-TW.md)

---

MudScript is a high-performance MUD (Multi-User Dungeon) engine implemented in Go, combining the flexibility of traditional LPC scripting with modern Web technologies. It is not just an interpreter, but a complete virtual world server.

### 🚀 Core Features

- **Powerful LPC Interpreter**: Optimized for LPC syntax, supporting multiple inheritance, complex macros (including parameterized ones), and LPC-style array/string slicing `[start..end]`. Non-LPC elements have been removed to ensure a lean and efficient core.
- **Hybrid Filesystem (Hybrid FS)**: Supports embedding the entire `mudlib` into the executable for "single-file distribution," while retaining an external disk overlay mechanism for hot-reloading and development.
- **Modern Web Interface**: Built-in WebSocket-based frontend supporting clickable interactions, automatic ID tagging, and mini-map displays.
- **High-performance NPC System**: Features intelligent heartbeats (active only when players are present), multi-race attribute bonuses, and a topic-based `ask` interaction system.
- **Security Protection**: Automatic HTML Sanitization to prevent XSS attacks, along with thread-safe environment variable management.

### 🛠️ Tech Stack

- **Backend**: Go 1.26.2 (using `embed` for resource packaging)
- **Frontend**: Vanilla JS / HTML5 / CSS Grid (Terminal and UI dual modes)
- **Scripting**: LPC-like scripts (located in `/mudlib`)
- **Protocol**: WebSocket & WebRTC (Signaling server supported)

### 📦 How to Compile

A robust `Makefile` is provided for cross-platform compilation.

**Compile Linux version:**
```bash
make fsmud
```

**Compile Windows version (.exe):**
```bash
make fsmud.exe
```
Binaries are stored in the `bin/` directory.

### 🎮 Quick Start

1. **Start Server**:
   ```bash
   ./bin/fsmud
   ```
2. **Login**: Open your browser and visit `http://localhost:8080`.
3. **Character Creation**: Enter your ID, then follow the guide to choose your **Race** and **Nature**, which affect your starting stats and skills.

### 🌌 Interstellar Network (Fantasy Space)

MudScript features powerful P2P cross-server connectivity. You can not only communicate with other servers but also physically "traverse" into their worlds.

1. **Start and Connect**: Run `make run` to automatically join the global Interstellar Hub.
2. **Interstellar Traverse (fsgoto)**: Enter `fsgoto <mudlib_id>` (e.g., `fsgoto fantasy.space`), and the system will handle lookup, joining, and teleportation.
   - **Ghost Mode**: While in a foreign world, you enter a "Ghost State." You can freely look and move but cannot take items, attack NPCs, or cause damage, ensuring extreme safety for cross-server travel.
   - **Auto-Sync**: Remote rooms, NPCs, and items are synchronized in the background automatically.
3. **Interstellar Chat**: Use `fs <message>` for real-time global chat across all connected servers.

### 🎮 Player Interaction & UI

In MudScript, you don't need to type long names manually.
- **Look**: Type `look` to see NPCs and their IDs, e.g., `[Guild Master Edmund(edmund)]`.
- **Click**: Directly click on NPC names in the web interface to execute `look`.
- **Ask**: Use `ask <ID> <topic>`. Examples:
    - `ask edmund help`
    - `ask edmund job`
    - `ask edmund topics` (list all available topics)

### 📂 Directory Structure

- `/cmd`: Server entry point (fsmud).
- `/driver`: MUD engine core and Efun implementations.
- `/evaluator`: LPC script evaluator and AST processing.
- `/mudlib`: Game content (rooms, NPCs, commands, headers).
- `/web/static`: Frontend web resources.
- [**Efuns Reference**](docs/README-efuns.md): Complete list of built-in functions.

---

## 🔗 Link
[https://wade-fs-fsmud-hub.hf.space](https://wade-fs-fsmud-hub.hf.space)

## 📜 License

This project is licensed under the MIT License.
