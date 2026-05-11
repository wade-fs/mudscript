// mudlib/std/user.c

#include "/include/config.h"

inherit "/cmds/cmd_movement.c";
inherit "/cmds/cmd_look.c";
inherit "/cmds/cmd_inventory.c";
inherit "/cmds/cmd_social.c";
inherit "/cmds/cmd_info.c";
inherit "/cmds/cmd_quit.c";
inherit "/cmds/cmd_help.c";
inherit "/cmds/cmd_alias.c";
inherit "/cmds/cmd_nickname.c";
inherit "/cmds/admin/cmd_demote.c";
inherit "/cmds/admin/cmd_grant.c";
inherit "/cmds/admin/cmd_promote.c";
inherit "/cmds/admin/cmd_revoke.c";

// ── 初始化 ───────────────────────────────────────────────
void create() {
	write_paths = ({ });
}

// ── 登入初始化 ───────────────────────────────────────────
// server.go 建立連線後呼叫 setup()，把所有指令綁定好
void setup() {
    set_heart_beat(1);
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

	// 管理指令
	if (role == "god" || role == "wizard") {
		cmd_promote_setup();
		cmd_demote_setup();
		cmd_grant_setup();
		cmd_revoke_setup();
    }

	if (!query_name()) {
        set_name(get_id()); // 預設名稱與 ID 相同
    }
}

// ── 玩家屬性 ────────────────────────────────────────────
string id;
void set_id(string i) { id = i; }
string get_id() { return id; }

string password;
void set_password(string p) { password = p; }
string get_password() { return password; }

string role;
string query_role() { return role; }
void set_role(string r) {
	if (r == "god" || r == "wizard" || r == "user") {
        role = r;
	}
}

string *write_paths;
string *query_write_paths() { return write_paths; }
int add_write_path(string path) {
    if (member_array(path, write_paths) != -1) { return 0; }
    write_paths += ({ path });
    return 1;
}
int remove_write_path(string path) {
    write_paths -= ({ path });
    return 1;
}

int has_write_access(string path) {
	if (role == "god") return 1;
    foreach (p in write_paths) {
        if (strsrch(path, p) == 0) { return 1; }
    }
    return 0;
}

// ── 基本查詢 ─────────────────────────────────────────────
string name;
string query_name()  { return name; }
void set_name(string n) { name = n; }

int level;
int query_level() { return level; }

int exp;
int query_exp() { return exp; }

int exp_to_next;
int query_exp_to_next() {
  if (exp_to_next <= exp) {
    exp_to_next = exp + 100;
  }
  return exp_to_next;
}

int hp;
int query_hp() { return hp; }

int max_hp;
int query_max_hp() {
  if (max_hp <= 0) {
    max_hp = 100;
  }
  return max_hp;
}

int mp;
int query_mp() { return mp; }

int max_mp;
int query_max_mp() {
  if (max_mp <= 0) {
    max_mp = 100;
  }
  return max_mp;
}

int attack;
int query_attack() { return attack; }

int defence;
int query_defence() { return defence; }

int gold;
int  query_gold()      { return gold; }
void gain_gold(int v)  { gold = gold + v; }
void lose_gold(int v)  { gold = gold - v; if (gold < 0) { gold = 0; } }

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

string query_save_file() { return "/data/user/" + id; }
int save() { return save_object(query_save_file()); }
int restore() { return restore_object(query_save_file()); }
