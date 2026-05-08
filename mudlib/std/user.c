// mudlib/std/user.c
// 玩家物件 — 重構版
//
// 設計原則：
//   所有 cmd 邏輯已抽離至 mudlib/cmds/cmd_*.c
//   user.c 只負責：
//     1. 玩家基本屬性（gold、name、hp…）
//     2. 繼承所有 cmd 模組
//     3. setup() 呼叫各模組的 *_setup()
//     4. 生命週期（heart_beat、on_death、save/restore）

#include "/include/config.h"

inherit "/cmds/cmd_movement.c";
inherit "/cmds/cmd_look.c";
inherit "/cmds/cmd_inventory.c";
inherit "/cmds/cmd_social.c";
inherit "/cmds/cmd_info.c";
inherit "/cmds/cmd_quit.c";
inherit "/cmds/cmd_help.c";
inherit "/cmds/cmd_alias.c";

// ── 玩家屬性 ────────────────────────────────────────────
int gold;
string name;
string password;
void set_password(string p) { password = p; }
string get_password() { return password; }

// ── 初始化 ───────────────────────────────────────────────
void create() {
    set_heart_beat(1);
}

// ── 基本查詢 ─────────────────────────────────────────────
string query_name()  { return name; }

int  query_gold()      { return gold; }
void gain_gold(int v)  { gold = gold + v; }
void lose_gold(int v)  { gold = gold - v; if (gold < 0) { gold = 0; } }

// ── 登入初始化 ───────────────────────────────────────────
// server.go 建立連線後呼叫 setup()，把所有指令綁定好
void setup() {
    enable_commands();

    // 各模組統一由自己的 *_setup() 負責 add_action
    cmd_movement_setup();
    cmd_look_setup();
    cmd_inventory_setup();
    cmd_social_setup();
    cmd_info_setup();
    cmd_quit_setup();
    cmd_help_setup();
    cmd_alias_setup();
}

// setup_player() 是 login.c 登入成功後呼叫的別名，保持相容
void setup_player() {
    setup();
}

// ── 心跳 ─────────────────────────────────────────────────
void heart_beat() {
    // 保留給 HP/MP 回復、戰鬥 tick 等使用
}

// ── 死亡 ─────────────────────────────────────────────────
void on_death() {
    write("\n你死亡了！你從混沌中甦醒，回到了起點...\n\n");
    object start = clone_object(START_ROOM);
    move_object(start);
    start->look_room();
    set_heart_beat(1);
}

// ── process_input：無法識別的指令 ───────────────────────
// 先嘗試展開 alias，若有展開則提示並讓 server.go 重新派送
// 若仍無法識別，回傳 0 讓 server.go 印出「什麼？」
int process_input(string input) {
    return 0;
}

mapping aliases = ([]); // 宣告並預設為空 mapping

// 給其他物件修改別名的介面
mapping query_aliases() { return aliases; }
void set_alias(string verb, string cmd) { aliases[verb] = cmd; }
void remove_alias(string verb) { m_delete(aliases, verb); }

// 將 expand_alias 移到這裡，讓 server.go 可以呼叫
string expand_alias(string input) {
    mixed ks = keys(aliases);
    if (sizeof(ks) == 0) { return input; }

    string verb;
    string rest;
    int sp = strsrch(input, " ");

    if (sp < 0) {
        verb = input;
        rest = "";
    } else {
        verb = substr(input, 0, sp);
        rest = substr(input, sp + 1, strlen(input) - sp - 1);
    }

    if (member_array(verb, ks) >= 0) {
        string expanded = aliases[verb];
        if (rest != "") { expanded = expanded + " " + rest; }
        return expanded;
    }
    return input;
}
