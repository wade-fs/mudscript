// std/user.c - 通用玩家物件基底類別 (World-Agnostic)
// 移除特定小說硬編碼，保留通用存檔路徑 /data/...

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/living.c";
inherit "/std/combat.c";

// ── 屬性宣告 ────────────────────────────────────────────
string id;
string password;
string role;         // "player", "wizard", "god"
string lang;         // 語系設定
string guild;        // 職業/公會
string guild_rank;
int    guild_exp;
int    bank_balance;
int    last_bank_time;
string *write_paths;
mapping aliases;
mapping quests;         // 任務紀錄
mapping quest_flags;    // 任務分支選擇紀錄
mapping muted_channels;
mapping explored_rooms;
string last_location;
string cwd;
string in_edit;
string current_mudlib;

// ── 存檔路徑 ─────────────────────────────────────────────
string query_save_file() {
    return "/data/user/" + id;
}

// ── 別名初始化 ─────────────────────────────────────────────
void init_aliases() {
    if (!aliases || sizeof(aliases) == 0) {
        aliases = ([
            "n" : "go north",    "s" : "go south",
            "e" : "go east",     "w" : "go west",
            "ne": "go northeast","nw": "go northwest",
            "se": "go southeast","sw": "go southwest",
            "u" : "go up",       "d" : "go down",
            "l" : "look",        "i" : "inventory",
            "sc": "score"
        ]);
    }
}

void create() {
    ::create();
    if (!quests)         quests = ([]);
    if (!quest_flags)    quest_flags = ([]);
    if (!muted_channels) muted_channels = ([]);
    if (!explored_rooms) explored_rooms = ([]);
    init_aliases();
    role = "player";
    lang = "zh-TW";
    current_mudlib = "";
    write_paths = ({});
}

// ── 設定與查詢 ──────────────────────────────────────────
void set_id(string v)     { id = v; }
string query_id()         { return id; }
string get_id()           { return id; }
void set_password(string v){ password = v; }
string query_password()   { return password; }
void set_role(string v)   { role = v; }
string query_role()       { return role; }
void set_lang(string v)   { lang = v; }
string query_lang()       { return lang; }
void set_guild(string v)  { guild = v; }
string query_guild()      { return guild; }
int  query_bank()         { return bank_balance; }
void set_bank(int v)      { bank_balance = v; }
string query_cwd()        { return cwd ? cwd : "/"; }
void set_cwd(string v)    { cwd = v; }
string query_last_location()        { return last_location; }
void set_last_location(string loc)  { last_location = loc; }
string query_current_mudlib()       { return current_mudlib ? current_mudlib : ""; }
void set_current_mudlib(string m)   { current_mudlib = m; }
string *query_write_paths()         { return write_paths ? write_paths : ({}); }
void set_write_paths(string *p)     { write_paths = p; }
mapping query_quests()    { return quests; }
mapping query_aliases()   { return aliases; }
void set_alias(string k, string v) { if (!aliases) aliases = ([]); aliases[k] = v; }
void remove_alias(string k)        { if (aliases) map_delete(aliases, k); }

// ── 任務與分支旗標 ────────────────────────────────────────
mixed query_quest(string qid) {
    if (!quests) quests = ([]);
    return quests[qid];
}
void set_quest(string qid, mixed data) {
    if (!quests) quests = ([]);
    quests[qid] = data;
}
mixed query_quest_flag(string key) {
    if (!quest_flags) return 0;
    return quest_flags[key];
}
void set_quest_flag(string key, mixed val) {
    if (!quest_flags) quest_flags = ([]);
    quest_flags[key] = val;
}
mapping query_all_quest_flags() {
    if (!quest_flags) quest_flags = ([]);
    return quest_flags;
}

// ── 探索 ─────────────────────────────────────────────────
void mark_explored(string room_path) {
    if (!explored_rooms) explored_rooms = ([]);
    explored_rooms[room_path] = 1;
}
int query_explored(string room_path) {
    if (!explored_rooms) return 0;
    return explored_rooms[room_path] ? 1 : 0;
}

// ── 存檔 / 讀檔 ─────────────────────────────────────────
void do_save() {
    if (!id || id == "") return;
    save_object(query_save_file());
}
void save() { do_save(); }

int do_restore() {
    if (!id || id == "") return 0;
    string sf = query_save_file();
    if (file_size(sf + ".o") > 0) {
        restore_object(sf);
        return 1;
    }
    return 0;
}

// ── 別名與輸入處理 ────────────────────────────────────────
string expand_alias(string input) {
    if (!aliases || !input || input == "") return input;
    string verb, rest;
    int sp_idx = strsrch(input, " ");
    if (sp_idx < 0) {
        verb = input;
        rest = "";
    } else {
        verb = substr(input, 0, sp_idx);
        rest = substr(input, sp_idx + 1, strlen(input) - sp_idx - 1);
    }
    if (aliases[verb]) {
        return rest != "" ? (aliases[verb] + " " + rest) : aliases[verb];
    }
    return input;
}

mixed process_input(string input) {
    input = trim(input);
    if (!input || input == "") return 0;

    string orig = input;
    input = expand_alias(input);

    if (substr(input, 0, 1) == "'") {
        string arg = substr(input, 1, strlen(input) - 1);
        return ::process_input("say " + arg);
    }

    int res = ::process_input(input);
    if (!res && input != orig) {
        return input;
    }
    return res;
}

// ── look 委派 ───────────────────────────────────────────
void do_look() {
    object room = environment(this_object());
    if (!room) { write("你不在任何地方。\n"); return; }
    write("{HIW}" + to_string(room->query_short()) + "{NOR}\n");
    write(to_string(room->query_long()));
    mapping ex = room->query_exits();
    if (ex && sizeof(ex) > 0) {
        write("{CYN}出口：{NOR} " + implode(keys(ex), "  ") + "\n");
    } else {
        write("{YEL}（此處無明顯出口）{NOR}\n");
    }
    object *inv = all_inventory(room);
    foreach (object ob in inv) {
        if (ob == this_object()) continue;
        write("  " + to_string(ob->query_short()) + " 在這裡。\n");
    }
}

void write_prompt() {
    write("> ");
}

void net_dead() {
    do_save();
    destruct(this_object());
}
