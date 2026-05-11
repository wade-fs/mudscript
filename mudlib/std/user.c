// mudlib/std/user.c

#include "/include/config.h"

// ── 屬性宣告 ────────────────────────────────────────────
string id, name, password, role;
int level, exp, exp_to_next, hp, max_hp, mp, max_mp, attack, defence, gold;
string *write_paths;
mapping aliases;
string *saved_inventory = ({ });
string last_location;

// ── 初始化 ───────────────────────────────────────────────
void init_aliases() {
    if (!aliases || sizeof(aliases) == 0) {
        aliases = ([
            "n" : "go north",
            "s" : "go south",
            "e" : "go east",
            "w" : "go west",
            "u" : "go up",
            "d" : "go down",
            "north" : "go north",
            "south" : "go south",
            "east" : "go east",
            "west" : "go west",
            "l" : "look",
            "i" : "inventory",
            "sc": "score"
        ]);
    }
}

void create() {
    init_aliases();
}

// ── 登入初始化 ───────────────────────────────────────────
// server.go 建立連線後呼叫 setup()，把所有指令綁定好
void setup() {
    init_aliases();
    set_heart_beat(1);
    enable_commands();

    // 🚩 這裡不再呼叫 cmd_xxx_setup()，因為改用 COMMAND_D 守護進程機制

	if (!name) {
        set_name(id);
    }

	// 恢復背包物品
	call_other(this_object(), "restore_inventory");

    // 處理進入世界的位置
    if (last_location) {
        object loc = load_object(last_location);
        if (loc) {
            move_object(loc);
            loc->look_room();
        } else {
            move_to_start();
        }
    } else {
        move_to_start();
    }

    call_other(load_object("/cmds/cmd_help.c"), "do_help_list", this_object(), "");
}

int process_input(string input) {
    string verb, arg;
    
    input = trim(input);
    if (!input || input == "") return 0;

    if (substr(input, 0, 1) == "'") {
        verb = "'";
        arg = substr(input, 1, strlen(input) - 1);
    } else if (substr(input, 0, 1) == ":") {
        verb = ":";
        arg = substr(input, 1, strlen(input) - 1);
    } else {
        int sp = strsrch(input, " ");
        if (sp < 0) {
            verb = input;
            arg = "";
        } else {
            verb = substr(input, 0, sp);
            arg = substr(input, sp + 1, strlen(input) - sp - 1);
        }
    }
    
    object cmd_d = load_object("/secure/command_d.c");
    if (!cmd_d) {
        write("系統錯誤：無法載入指令守護進程。\n");
        return 1;
    }
    return cmd_d->execute(this_object(), verb, arg);
}

void move_to_start() {
    object start = clone_object(START_ROOM);
    if (start) {
        move_object(start);
        start->look_room();
    } else {
        write("致命錯誤：找不到起始點 " + START_ROOM + "\n");
    }
}

// ── 基本介面 ─────────────────────────────────────────────
void set_id(string i) { id = i; }
string get_id() { return id; }
void set_password(string p) { password = p; }
string get_password() { return password; }
string query_role() { return role; }
void set_role(string r) { if (r == "god" || r == "wizard" || r == "user") role = r; }
string query_name() { return name; }
void set_name(string n) { name = n; }
void set_nickname(string n) { name = n; }
int query_level() { return level; }
int query_exp() { return exp; }
int query_exp_to_next() { if (exp_to_next <= exp) exp_to_next = exp + 100; return exp_to_next; }
int query_hp() { return hp; }
int query_max_hp() { if (max_hp <= 0) max_hp = 100; return max_hp; }
int query_mp() { return mp; }
int query_max_mp() { if (max_mp <= 0) max_mp = 100; return max_mp; }
int query_attack() { return attack; }
int query_defence() { return defence; }
int query_gold() { return gold; }
void add_gold(int g) { gold += g; }

string *query_write_paths() { return write_paths; }
void add_write_path(string p) {
    if (member_array(p, write_paths) == -1) {
        write_paths += ({ p });
    }
}
void remove_write_path(string p) {
    write_paths -= ({ p });
}

// ── 心跳 ─────────────────────────────────────────────────
void heart_beat() {
    // 🚀 利用心跳，定時將 score 資訊以 JSON 格式推送到 Info 區
    object cmd_info = load_object("/cmds/cmd_info.c");
    if (cmd_info) {
        cmd_info->main(this_object(), "");
    }
}

// ── 死亡 ─────────────────────────────────────────────────
void on_death() {
    write("\n你死亡了！你從混沌中甦醒，回到了起點...\n\n");
    object start = clone_object(START_ROOM);
    move_object(start);
    start->look_room();
    set_heart_beat(1);
}

string query_save_file() { return "/data/user/" + id; }

int save() {
	// 在存檔前，先記錄背包裡所有物品的檔名
	object *inv = all_inventory(this_object());
	saved_inventory = ({ });
	for (int i = 0; i < sizeof(inv); i++) {
		string filename = object_name(inv[i]);
		// 去掉 clone 的編號 (例如 /obj/sword.c#123 -> /obj/sword.c)
		int pos = strsrch(filename, "#");
		if (pos != -1) {
			filename = substr(filename, 0, pos);
		}
		saved_inventory += ({ filename });
	}

    // 紀錄目前位置
    object env = environment(this_object());
    if (env) {
        last_location = object_name(env);
        // 同樣去掉 clone 編號
        int pos_env = strsrch(last_location, "#");
        if (pos_env != -1) {
            last_location = substr(last_location, 0, pos_env);
        }
    }

	return save_object(query_save_file());
}

int restore() { return restore_object(query_save_file()); }

void restore_inventory() {
	if (!sizeof(saved_inventory)) return;
	
	for (int i = 0; i < sizeof(saved_inventory); i++) {
		object ob = clone_object(saved_inventory[i]);
		if (ob) {
			move_object(ob, this_object());
		}
	}
	// 清空紀錄，避免重複恢復（存檔時會重新產生）
	saved_inventory = ({ });
}

// 給其他物件修改別名的介面
mapping query_aliases() { return aliases; }
void set_alias(string verb, string cmd) { aliases[verb] = cmd; }
void remove_alias(string verb) { m_delete(aliases, verb); }
string expand_alias(string input) {
    mixed ks = keys(aliases);
    if (!ks) { return input; }

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
        if (rest) { expanded = expanded + " " + rest; }
        return expanded;
    }
    return input;
}
