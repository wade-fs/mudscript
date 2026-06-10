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
- **Light Minecraft (LM) System**: A built-in sandbox world system supporting 2D canvas rendering, real-time block interaction (dig/place), and **Emoji-based World Building**. You can import complex terrains and NPC layouts directly from text strings or files. See [**LM System Guide**](docs/README-lm.md) for details.
- **Hybrid Filesystem (Hybrid FS)**: Supports embedding the entire `mudlib` into the executable for "single-file distribution," while retaining an external disk overlay mechanism for hot-reloading and development.
- **Modern Web Interface**: Built-in WebSocket-based frontend supporting clickable interactions, automatic ID tagging, and mini-map displays.
- **High-performance NPC System**: Features intelligent heartbeats (active only when players are present), multi-race attribute bonuses, and a topic-based `ask` interaction system.
- **Security Protection**: Automatic HTML Sanitization to prevent XSS attacks, along with thread-safe environment variable management.

### 🛠️ Tech Stack

- **Backend**: Go 1.26.2 (using `embed` for resource packaging)
- **Frontend**: Vanilla JS / HTML5 / CSS Grid (Terminal and UI dual modes)
- **Scripting**: LPC-like scripts (located in `/mudlib`)
- **Protocol**: WebSocket & WebRTC (Signaling server supported)

### 📦 Compilation & Build Options

MudScript supports multiple build targets to balance portability and binary size. All builds use a unified entry point but different embedded assets via build tags.

| Target | Description | Binary Name | Size (approx) |
| :--- | :--- | :--- | :--- |
| `make fsmud` | **Modern MUD**: Optimized for the `fsmud/` mudlib. | `fsmud` | ~12MB |
| `make fs` | **Legacy MUD**: Optimized for the legacy `fs/` mudlib. | `fs` | ~40MB |
| `make universal` | **All-in-One**: Includes BOTH `fsmud` and `fs`. | `mud-universal` | ~41MB |
| `make mudscript` | **Pure Driver**: No embedded assets (disk files only). | `mudscript` | ~11MB |

**Windows Support**: Use `.exe` suffix (e.g., `make fsmud.exe`).

### 🎮 Running the Server

The unified entry point allows running any mudlib with appropriate flags.

```bash
# Option 1: Run the standard Modern MUD
./bin/fsmud

# Option 2: Run the Legacy FS MUD (Requires -legacy flag for compatibility)
./bin/fs -mudlib fs -master /adm/obj/master.c -legacy

# Option 3: Run using the pure driver (Reads from disk)
./bin/mudscript -mudlib fsmud -master master.c
```

**Common Command Flags:**
- `-mudlib <path>`: Directory of the mudlib (Default: `fsmud`).
- `-master <file>`: Path to the master object (Default: `master.c`).
- `-legacy`: Enable legacy LPC compatibility (strips modifiers, standard heartbeats).
- `-port <num>`: Web interface / WebSocket port (Default: `8080`).
- `-telnet <num>`: Telnet server port for automation/legacy clients (Default: `4000`).

### 🚀 Quick Start

1. **Start Server**: `./bin/fsmud`
2. **Login**: Open browser to `http://localhost:8080`.
3. **Explore**: Enter your ID and follow the guide to choose your **Race** and **Nature**.

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

### 💻 Web IDE (Online Editing)

MudScript features a built-in Web IDE for admins and wizards, allowing you to edit and save LPC scripts directly from your browser.
- **Access**: Log in with an account having `god` or `wizard` role.
- **Usage**: You can use the web ide to edit files, it supports real-time saving and instant updates.

### 📂 Directory Structure

- `/cmd`: Server entry point (fsmud).
- `/driver`: MUD engine core and Efun implementations.
- `/evaluator`: LPC script evaluator and AST processing.
- `/mudlib`: Game content (rooms, NPCs, commands, headers).
- `/web/static`: Frontend web resources.
- [**Efuns Reference**](docs/README-efuns.md): Complete list of built-in functions.
- [**LM System Guide**](docs/README-lm.md): Documentation for the Light Minecraft sandbox world.
- [**History / Changelog**](History.md): Version history and update logs.

---

## 🔗 Link
[https://wade-fs-fsmud-hub.hf.space](https://wade-fs-fsmud-hub.hf.space)

## 📜 License

This project is licensed under the MIT License.
