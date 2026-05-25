// mudlib/std/user.c

#include "/include/config.h"
#include "/include/ansi.h"
#include "/include/race.h"

inherit "/std/living.c";
inherit "/std/combat.c";

// ── 屬性宣告 ────────────────────────────────────────────
string id, password, role;
string full_id;  // Fantasy Space 全域識別字：username@mudlib_id，例如 wade@fantasy.space
string nature;
string guild; // 🚀 新增：職業/公會
string guild_rank; // 🚀 新增：公會職位
string lang; // 🚀 新增：語系設定
int    guild_exp;  // 🚀 新增：公會貢獻/經驗
int    bank_balance; // 🚀 新增：銀行存款
int    last_bank_time; // 🚀 新增：上次計算利息時間
string *write_paths;
mapping aliases;
mapping quests; // 🚀 新增：任務紀錄
mapping muted_channels; // 🚀 新增：屏蔽的頻道
mapping explored_rooms; // 🚀 新增：已探索房間 ([ "room_file": 1 ])
string *saved_inventory = ({ });
string last_location;

// ── 查詢 ──────────────────────────────────────────────────

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

// 🚀 新增：跨服狀態追蹤
string current_mudlib; // 目前所在的 mudlib ID，空代表本機
string data_base_path; // 當前資料庫相對路徑，本機為 "/mudlib/data/"，遠端為 "/mudlib/data/fs_cache/<id>/"

void create() {
    ::create();
    if (!quests) quests = ([]);
    if (!muted_channels) muted_channels = ([]);
    if (!explored_rooms) explored_rooms = ([]);
    init_aliases();
    
    current_mudlib = "";
    data_base_path = "/mudlib/data/";
}

// ── 查詢函式 ────────────────────────────────────────────
string query_current_mudlib() { return current_mudlib; }
string query_data_base_path() { return data_base_path; }

// 🚀 新增：動態取得起始點 (支援跨服)
string query_start_room() {
    if (current_mudlib != "") {
        object fs_d = find_object("/secure/fs_d.c");
        if (fs_d) {
            mapping joined = fs_d->query_joined_muds();
            if (joined && joined[current_mudlib]) {
                string ent = joined[current_mudlib]["entrance"];
                if (ent && ent != "") {
                    return FS_CACHE_DIR + "/" + current_mudlib + ent;
                }
            }
        }
        // 若找不到遠端入口，退而求其次回傳緩存目錄的預設起始點
        return FS_CACHE_DIR + "/" + current_mudlib + START_ROOM;
    }
    return START_ROOM;
}

// 當環境改變時，自動更新跨服狀態
int move(mixed dest, string dir) {
    int res = ::move(dest, dir);
    if (res) {
        object env = environment(this_object());
        if (env) {
            string ename = object_name(env);
            // 判斷是否為遠端緩存路徑，格式如：/data/fs_cache/mudlib_id/area/...
            if (strsrch(ename, FS_CACHE_DIR) == 0) {
                // 提取 mudlib_id
                string rel = substr(ename, strlen(FS_CACHE_DIR) + 1, strlen(ename));
                int slash = strsrch(rel, "/");
                if (slash != -1) {
                    current_mudlib = substr(rel, 0, slash);
                    data_base_path = FS_CACHE_DIR + "/" + current_mudlib + "/";
                }
            } else {
                current_mudlib = "";
                data_base_path = "/mudlib/data/";
            }
        }
    }
    return res;
}

// ── 登入初始化 ───────────────────────────────────────────
void setup() {
    if (!quests) quests = ([]);
    if (!muted_channels) muted_channels = ([]);
    if (!explored_rooms) explored_rooms = ([]);
    if (!last_bank_time) last_bank_time = time();
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
            loc->look_room(this_object());
        } else {
            move_to_start();
        }
    } else {
        move_to_start();
    }

    call_other(load_object("/cmds/cmd_help.c"), "do_help_list", this_object(), "");

    // 🚀 新增：發送 UI 初始化資訊給前端
    string l = query_lang();
    object lang_d = load_object("/secure/language_d.c");

    mapping socials = load_object("/secure/social_d.c")->get_ui_list();
    write(sprintf("{\"ui\": \"socials\", \"title\": \"%s\", \"data\": %s}", 
        lang_d->translate("label_actions", l), json_encode(socials)));

    mapping cmds = load_object("/secure/command_d.c")->query_categorized_commands(l);
    write(sprintf("{\"ui\": \"commands\", \"title\": \"%s\", \"data\": %s}", 
        lang_d->translate("label_commands", l), json_encode(cmds)));
}

int process_input(string input) {
    string verb, arg;
    
    input = trim(input);
    if (!input) return 0;

    // 1. 處理特殊符號指令 (如 ' 代表 say, : 代表 emote)
    if (substr(input, 0, 1) == "'") {
        verb = "'";
        arg = substr(input, 1, strlen(input) - 1);
        return ::process_input("say " + arg);
    } else if (substr(input, 0, 1) == ":") {
        verb = ":";
        arg = substr(input, 1, strlen(input) - 1);
        return ::process_input("emote " + arg);
    } 
    
    // 2. 呼叫基底類別處理 (含 command_d 呼叫)
    int res = ::process_input(input);
    if (res) return res;

    // 3. 失敗訊息
    write(_t("what") + "\n");
    return 0;
}

void move_to_start() {
    string start_path = query_start_room();
    object start = load_object(start_path);
    if (start) {
        move_object(start);
        start->look_room(this_object());
    } else {
        write("致命錯誤：找不到起始點 " + start_path + "\n");
    }
}

// ── 基本介面 ─────────────────────────────────────────────
void set_id(mixed i) { ::set_id(i); if (stringp(i)) id = i; }
string get_id() { return id; }
void set_password(string p) { password = p; }
string get_password() { return password; }
string query_role() { return role; }
string query_full_id() {
    if (full_id && full_id != "") return full_id;
    return id + "@" + FS_MUDLIB_ID;
}
void set_full_id(string fid) { full_id = fid; }
void set_role(string r) { if (r == "god" || r == "wizard" || r == "user") role = r; }
void set_guild(string g) { guild = g; }
string query_guild() { return guild; }
void set_guild_rank(string r) { guild_rank = r; }
string query_guild_rank() { return guild_rank; }
void set_lang(string l) { lang = l; }
string query_lang() { return lang; }
void add_guild_exp(int v) { guild_exp += v; }
int query_guild_exp() { return guild_exp; }

// ── 銀行系統介面 ─────────────────────────────────────────────
int query_bank_balance() { return bank_balance; }
void set_bank_balance(int v) { bank_balance = v; }
void add_bank_balance(int v) { bank_balance += v; if (bank_balance < 0) bank_balance = 0; }
int query_last_bank_time() { return last_bank_time; }
void set_last_bank_time(int v) { last_bank_time = v; }

void set_nickname(string n) { set_name(n); }

// ── 頻道管理 ─────────────────────────────────────────────
int is_channel_open(string ch) {
    if (!muted_channels) return 1;
    return !muted_channels[ch];
}
void set_channel_status(string ch, int open) {
    if (!muted_channels) muted_channels = ([]);
    if (open) m_delete(muted_channels, ch);
    else muted_channels[ch] = 1;
}
mapping query_muted_channels() { return muted_channels; }

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

// ── 寵物與坐騎介面 ─────────────────────────────────────────────
object query_pet() { return active_pet; }
void   set_pet(object ob) { active_pet = ob; }
int    query_riding() { return is_riding; }
void   set_riding(int v) { is_riding = v; }

// ── 地圖探索介面 ─────────────────────────────────────────────
mapping query_explored_rooms() { return explored_rooms; }
void record_exploration(string room_file) {
    if (!explored_rooms) explored_rooms = ([]);
    // room_file 已由 room.c 用 object_name(this_object()) 傳入，直接當 key 用
    explored_rooms[room_file] = 1;
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
int heart_beat_count = 0;
void heart_beat() {
    if (is_dead) return;
    
    // 執行戰鬥回合
    combat_heart_beat();

    // 🚀 每 5 秒發送一次狀態資訊給前端 UI (減少洗頻)
    heart_beat_count++;
    if (heart_beat_count >= 5) {
        heart_beat_count = 0;
        object cmd_info = load_object("/cmds/cmd_info.c");
        if (cmd_info) {
            cmd_info->main(this_object(), "score", "");
        }
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

