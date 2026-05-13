// mudlib/std/user.c

#include "/include/config.h"
#include "/include/ansi.h"
#include "/include/race.h"

inherit "/std/living.c";
inherit "/std/combat.c";

// ── 屬性宣告 ────────────────────────────────────────────
string id, password, role;
string nature;
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
    ::create();
    init_aliases();
}

// ── 登入初始化 ───────────────────────────────────────────
void setup() {
    init_aliases();
    set_heart_beat(1);
    enable_commands();

    if (!name) {
        set_name(id);
    }

    recalc_stats();

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

    int res = cmd_d->execute(this_object(), verb, arg);
    if (res) return res;

    return 0;
}

void move_to_start() {
    object start = load_object(START_ROOM);
    if (start) {
        move_object(start);
        start->look_room();
    } else {
        write("致命錯誤：找不到起始點 " + START_ROOM + "\n");
    }
}

// ── 基本介面 ─────────────────────────────────────────────
void set_id(mixed i) { ::set_id(i); if (stringp(i)) id = i; }
string get_id() { return id; }
void set_password(string p) { password = p; }
string get_password() { return password; }
string query_role() { return role; }
void set_role(string r) { if (r == "god" || r == "wizard" || r == "user") role = r; }
void set_nickname(string n) { set_name(n); }

void set_nature(string n) { nature = n; }
string query_nature() { return nature; }

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
    if (is_dead) return;
    
    // 執行戰鬥回合
    combat_heart_beat();
}

// ── 死亡 ─────────────────────────────────────────────────
void on_death() {
    write(RED("\n你感覺到世界在眼前漸漸模糊... 你死亡了。\n") + NOR);
    write("一股強大的力量將你的靈魂拉回了中央廣場。\n\n");
    
    // 死亡懲罰：遺失一部分金幣
    if (gold > 0) {
        int lost = gold / 5;
        gold -= lost;
        write(YEL("你遺失了 " + sprintf("%d", lost) + " 枚金幣。\n") + NOR);
    }
    
    // 恢復基礎狀態
    is_dead = 0;
    hp = max_hp / 2; // 復活時只有一半血
    mp = max_mp / 2;
    
    // 回到起始點
    move_to_start();
    save();
}

string query_save_file() { return "/data/user/" + id; }

int save() {
	object *inv = all_inventory(this_object());
	saved_inventory = ({ });
	for (int i = 0; i < sizeof(inv); i++) {
		string filename = object_name(inv[i]);
		int pos = strsrch(filename, "#");
		if (pos != -1) {
			filename = substr(filename, 0, pos);
		}
		saved_inventory += ({ filename });
	}

    object env = environment(this_object());
    if (env) {
        last_location = object_name(env);
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
	saved_inventory = ({ });
}

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

