// mudlib/std/user.c

#include "/include/config.h"
#include "/include/race.h"

// ── 屬性宣告 ────────────────────────────────────────────
string id, name, password, role;
string race, nature;
mapping skills;
int level, exp, exp_to_next, hp, max_hp, mp, max_mp, attack, defence, gold;
string *write_paths;
mapping aliases;
string *saved_inventory = ({ });
string last_location;

// ── 屬性宣告 (六圍) ──────────────────────────────────────
// 注意：這些應該與 living.c 同名，因為 user.c 雖然沒繼承 living.c (目前是 clone /std/user.c 但 driver 處理 interactive)
// 其實 user.c 應該繼承 living.c 比較好。讓我們檢查一下。
// (發現原本 user.c 沒繼承 living.c，這是個架構問題，但我先照原本的補上)
int stat_str, stat_dex, stat_int, stat_con, stat_wis, stat_cha;

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
    if (!skills) skills = ([]);
}

// ── 屬性計算 ───────────────────────────────────────────
void recalc_stats() {
    max_hp  = stat_con * MAX_HP_PER_CON + level * 5;
    max_mp  = stat_int * 5 + stat_wis * 3 + level * 3;
    attack  = BASE_ATTACK  + stat_str * 2;
    defence = BASE_DEFENCE + stat_con;
    
    if (hp > max_hp) hp = max_hp;
    if (mp > max_mp) mp = max_mp;
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

    // 🚩 這裡可以擴充：如果全域指令沒找到，嘗試在環境中尋找具備特定互動能力的 NPC
    object env = environment(this_object());
    if (env) {
        object *inv = all_inventory(env);
        int i;
        for (i = 0; i < sizeof(inv); i++) {
            object ob = inv[i];
            // 排除自己，且只找生物 (NPC)
            if (ob && living(ob) && ob != this_object()) {
                if (ob->handle_interaction(verb, arg)) return 1;
            }
        }
    }

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
void set_id(string i) { id = i; }
string get_id() { return id; }
void set_password(string p) { password = p; }
string get_password() { return password; }
string query_role() { return role; }
void set_role(string r) { if (r == "god" || r == "wizard" || r == "user") role = r; }
string query_name() { return name; }
void set_name(string n) { name = n; }
void set_nickname(string n) { name = n; }

void set_level(int l) { level = l; }
void set_hp(int v) { hp = v; }
void set_mp(int v) { mp = v; }

void set_race(string r) { race = r; }
string query_race() { return race; }
void set_nature(string n) { nature = n; }
string query_nature() { return nature; }

void set_skill(string s, int v) { skills[s] = v; }
int query_skill(string s) { return skills[s]; }
mapping query_skills() { return skills; }

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

int query_stat(string s) {
    if (s == "str") return stat_str;
    if (s == "dex") return stat_dex;
    if (s == "int") return stat_int;
    if (s == "con") return stat_con;
    if (s == "wis") return stat_wis;
    if (s == "cha") return stat_cha;
    return 0;
}
void set_stat(string s, int v) {
    if (s == "str") stat_str = v;
    if (s == "dex") stat_dex = v;
    if (s == "int") stat_int = v;
    if (s == "con") stat_con = v;
    if (s == "wis") stat_wis = v;
    if (s == "cha") stat_cha = v;
}

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

