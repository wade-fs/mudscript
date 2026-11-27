// std/npc.c - 通用 NPC 基底類別 (World-Agnostic)
// 世界層可繼承並擴充特定小說的行為與屬性

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/living.c";

// ── NPC 基本屬性 ─────────────────────────────────────────
int     exp_reward;     // 擊殺後給予的經驗值
int     gold_reward;    // 掉落金幣
mixed   drop_list;      // 掉落物清單
mapping harvest_data;   // 可採集資源
int     respawn_time;   // 重生時間（秒），0=不重生
string  aggro_msg;      // 主動攻擊訊息

// ── 行為屬性 ─────────────────────────────────────────────
int     aggressive;     // 是否主動攻擊
int     wander_chance;  // 每次心跳隨機移動機率 (0~100)
string  home_room;      // 出生點

// ── 對話支援 ─────────────────────────────────────────────
mapping dialogue_tree;  // JSON 對話樹快取
string  dialogue_id;    // 對話樹識別 ID

void create() {
    ::create();
    enable_commands();

    set_name("怪物");
    set_short("一隻怪物");
    set_long("這是一隻普通的怪物。\n");
    set_id(({"monster", "怪物"}));

    level       = 1;
    exp_reward  = 50;
    gold_reward = 10;
    drop_list   = ({});
    harvest_data = ([]);
    respawn_time = 0;
    aggressive  = 0;
    wander_chance = 0;

    recalc_stats();
    hp = max_hp;
    mp = max_mp;
}

// ── 設定與查詢 ──────────────────────────────────────────
void set_exp_reward(int v)      { exp_reward = v; }
int  query_exp_reward()         { return exp_reward; }
void set_gold_reward(int v)     { gold_reward = v; }
int  query_gold_reward()        { return gold_reward; }
void set_drop_list(mixed v)     { drop_list = v; }
mixed query_drop_list()         { return drop_list; }
void set_home_room(string r)    { home_room = r; }
string query_home_room()        { return home_room; }
void set_aggressive(int v)      { aggressive = v; }
int  query_aggressive()         { return aggressive; }
void set_dialogue_id(string id) { dialogue_id = id; }
string query_dialogue_id()      { return dialogue_id; }

// ── 心跳 ────────────────────────────────────────────────
void heart_beat() {
    // 子類別可覆寫
}

// ── 對話入口（供 talk/ask 指令呼叫） ─────────────────────
mixed query_dialogue(string topic) {
    if (dialogue_tree && dialogue_tree[topic]) {
        return dialogue_tree[topic];
    }
    return 0;
}

void set_dialogue_tree(mapping tree) { dialogue_tree = tree; }
