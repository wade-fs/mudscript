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
mapping quests; // 🚀 新增：任務紀錄
object  leader; // 🚀 新增：跟隨目標
object *followers; // 🚀 新增：跟隨者清單
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
    if (!quests) quests = ([]);
    if (!followers) followers = ({});
    init_aliases();
}

// ── 登入初始化 ───────────────────────────────────────────
void setup() {
    if (!quests) quests = ([]);
    if (!followers) followers = ({});
    init_aliases();
    set_heart_beat(1);
    enable_commands();

    if (!name) {
        set_name(id);
    }

    recalc_stats();

	// 🚀 新增：賦予種族天性
	if (race == "dwarf") {
		set_skill("forging", 5);
	} else if (race == "elf") {
		set_skill("magic", 5);
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
    if (!input) return 0;

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

// ── 任務系統介面 ─────────────────────────────────────────────
mapping query_quests() { return quests; }
void set_quest(string qid, mapping data) {
    if (!quests) quests = ([]);
    quests[qid] = data;
}
void update_quest_progress(string qid, string key, mixed val) {
    if (!quests[qid]) return;
    if (!quests[qid]["progress"]) quests[qid]["progress"] = ([]);
    quests[qid]["progress"][key] = val;
}
mapping query_quest(string qid) { return quests[qid]; }

// ── 組隊與跟隨介面 ─────────────────────────────────────────────
object  query_leader() { return leader; }
void    set_leader(object ob) { leader = ob; }
object *query_followers() { return followers; }
void    add_follower(object ob) { if (member_array(ob, followers) == -1) followers += ({ ob }); }
void    remove_follower(object ob) { followers -= ({ ob }); }

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

    // 🚀 定期發送狀態資訊給前端 UI
    object cmd_info = load_object("/cmds/cmd_info.c");
    if (cmd_info) {
        cmd_info->main(this_object(), "score", "");
    }
}

// ── 死亡 ─────────────────────────────────────────────────
void on_death() {
    write(RED("\n你感覺到世界在眼前漸漸模糊... 你死亡了。\n"));
    write("你的靈魂緩緩脫離了肉體，進入了一片純白的世界...\n\n");

    
    // 產生屍體
    object corpse = clone_object("/std/corpse.c");
    if (corpse) {
        corpse->set_owner(query_name());
        move_object(corpse, environment(this_object()));
    }

    // 死亡懲罰：遺失一部分金幣
    if (gold > 0) {
        int lost = gold / 5;
        gold -= lost;
        write(YEL("你遺失了 " + sprintf("%d", lost) + " 枚金幣。\n"));
    }

    
    // 移至祈願所
    object prayer_room = load_object("/std/prayer_room.c");
    if (prayer_room) {
        move_object(prayer_room);
    }

    // 10 秒後復活 (對應屍體消失時間)
    call_out("revive", 10);
    save();
}

void revive() {
    write(HIY("\n一陣溫暖的光芒包圍了你，你感覺到生命力正在重新注入靈魂...\n"));
    write("你在中央廣場睜開了眼睛。\n\n");

    // 恢復基礎狀態
    is_dead = 0;
    hp = max_hp / 2; // 復活時只有一半血
    mp = max_mp / 2;
    set_heart_beat(1);

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

