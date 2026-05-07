// mudlib/user.c - 玩家物件

#include "/include/config.h"

inherit "/std/living.c";
inherit "/std/combat.c";

int     gold;          // 持有金幣

void create() {
    ::create();
    set_name("旅者");
    set_short("一位旅者");
    set_long("這是一位踏上冒險之旅的旅者。\n");
    set_id(({"player", "旅者"}));

    // 玩家初始屬性比基底略高
    stat_str = 12;  stat_dex = 12;
    stat_int = 12;  stat_con = 12;
    stat_wis = 12;  stat_cha = 12;
    recalc_stats();
    hp = max_hp;
    mp = max_mp;

    gold = 100;
    set_heart_beat(1);
}

// ── 金幣 ────────────────────────────────────────────────────
int  query_gold()      { return gold; }
void gain_gold(int v)  { gold = gold + v; }
void lose_gold(int v)  { gold = gold - v; if (gold < 0) { gold = 0; } }

// ── 登入初始化 ───────────────────────────────────────────────
void setup() {
    enable_commands();

    // 移動指令
    add_action("do_move", "north");  add_action("do_move", "south");
    add_action("do_move", "east");   add_action("do_move", "west");
    add_action("do_move", "up");     add_action("do_move", "down");
    add_action("do_move", "go");

    // 查看
    add_action("do_look",      "look");
    add_action("do_look",      "l");
    add_action("do_examine",   "examine");
    add_action("do_examine",   "ex");

    // 物品
    add_action("do_inventory", "inventory");
    add_action("do_inventory", "i");
    add_action("do_get",       "get");
    add_action("do_drop",      "drop");
    add_action("do_wear",      "wear");
    add_action("do_wield",     "wield");
    add_action("do_remove",    "remove");

    // 狀態
    add_action("do_score",     "score");
    add_action("do_score",     "status");

    // 戰鬥
    add_action("do_kill",      "kill");
    add_action("do_kill",      "attack");
    add_action("do_flee",      "flee");
    add_action("do_skills",    "skills");
    add_action("do_fireball",  "fireball");
    add_action("do_heal",      "heal");

    // 社交
    add_action("do_say_cmd",   "say");
    add_action("do_say_cmd",   "'");
    add_action("do_emote",     "emote");
    add_action("do_emote",     ":");

    // 系統
    add_action("do_name",      "name");
    add_action("do_quit",      "quit");
    add_action("do_quit",      "exit");
    add_action("do_help",      "help");

    // 移動到起始房間
    object start = clone_object(START_ROOM);
    move_object(start);
    start->look_room();
}

void init() {}

// ── 心跳：每 2 秒觸發 ──────────────────────────────────────
void heart_beat() {
    if (is_dead) { return; }

    // 緩慢恢復 HP/MP（非戰鬥時）
    if (!in_combat) {
        if (hp < max_hp) { heal_hp(max_hp / 20 + 1); }
        if (mp < max_mp) {
            mp = mp + max_mp / 30 + 1;
            if (mp > max_mp) { mp = max_mp; }
        }
    }

    // 戰鬥回合
    combat_heart_beat();
}

// ── 死亡 ────────────────────────────────────────────────────
void on_death() {
    is_dead = 0;  // 玩家死亡後復活
    hp = max_hp / 4;
    mp = max_mp / 4;
    in_combat     = 0;
    combat_target = 0;

    write("\n☠️  你死亡了！你從混沌中甦醒，回到了起點...\n\n");
    object start = clone_object(START_ROOM);
    move_object(start);
    start->look_room();
    set_heart_beat(1);
}

// ── 查看指令 ──────────────────────────────────────────────
int do_look(string arg) {
    object here = environment(this_object());
    if (!here) { write("你飄浮在虛空中。\n"); return 1; }

    if (!arg) {
        here->look_room();
        return 1;
    }

    // 看房間裡的物件
    object target = present(arg, here);
    if (target) {
        write(target->query_long());
        return 1;
    }

    // 看背包裡的物件
    target = present(arg, this_object());
    if (target) {
        write(target->query_long());
        return 1;
    }

    // 看房間裝飾物
    string item_desc = here->look_at_item(arg);
    if (item_desc != "") {
        write(item_desc + "\n");
        return 1;
    }

    write("你看不到叫「" + arg + "」的東西。\n");
    return 1;
}

int do_examine(string arg) {
    return do_look(arg);
}

// ── 移動指令 ──────────────────────────────────────────────
int do_move(string arg) {
    object here = environment(this_object());
    if (!here) { write("你不在任何地方。\n"); return 1; }

    string dir = arg;
    // 處理 "go north" 形式
    if (arg == "go") {
        write("要往哪裡去？例如：go north\n");
        return 1;
    }

    // 交給房間處理
    return here->do_go(dir);
}

// ── 物品指令 ──────────────────────────────────────────────
int do_inventory(string arg) {
    write("=== 背包 ===\n");
    mixed inv = all_inventory(this_object());
    if (sizeof(inv) == 0) {
        write("（空的）\n");
    } else {
        int i;
        for (i = 0; i < sizeof(inv); i++) {
            write("  " + inv[i]->query_short() + "\n");
        }
    }
    write("持有金幣：" + sprintf("%d", gold) + "\n");
    return 1;
}

int do_get(string arg) {
    if (!arg) { write("撿起什麼？\n"); return 1; }
    object here = environment(this_object());
    object item = present(arg, here);
    if (!item) {
        write("這裡沒有叫「" + arg + "」的東西。\n");
        return 1;
    }
    if (living(item)) {
        write("你不能撿起活物。\n");
        return 1;
    }
    move_object(item, this_object());
    write("你撿起了 " + item->query_short() + "。\n");
    say(query_name() + " 撿起了 " + item->query_short() + "。\n");
    return 1;
}

int do_drop(string arg) {
    if (!arg) { write("丟下什麼？\n"); return 1; }
    object item = present(arg, this_object());
    if (!item) {
        write("你身上沒有叫「" + arg + "」的東西。\n");
        return 1;
    }
    object here = environment(this_object());
    move_object(item, here);
    write("你放下了 " + item->query_short() + "。\n");
    say(query_name() + " 放下了 " + item->query_short() + "。\n");
    return 1;
}

int do_wear(string arg) {
    if (!arg) { write("穿上什麼？\n"); return 1; }
    object item = present(arg, this_object());
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    if (item->query_item_type() != ITEM_ARMOUR) {
        write(item->query_short() + " 不是防具。\n");
        return 1;
    }
    if (!equip(item)) {
        write("無法裝備 " + item->query_short() + "。\n");
        return 1;
    }
    write("你穿上了 " + item->query_short() +
          "。（防禦力 +" + sprintf("%d", item->query_defence()) + "）\n");
    return 1;
}

int do_wield(string arg) {
    if (!arg) { write("裝備什麼武器？\n"); return 1; }
    object item = present(arg, this_object());
    if (!item) { write("你身上沒有叫「" + arg + "」的東西。\n"); return 1; }
    if (item->query_item_type() != ITEM_WEAPON) {
        write(item->query_short() + " 不是武器。\n");
        return 1;
    }
    if (!equip(item)) {
        write("無法裝備 " + item->query_short() + "。\n");
        return 1;
    }
    write("你裝備了 " + item->query_short() +
          "。（攻擊力 +" + sprintf("%d", item->query_attack()) + "）\n");
    return 1;
}

int do_remove(string arg) {
    if (!arg) { write("脫下什麼？\n"); return 1; }
    mixed slots = ({"weapon", "head", "body", "hands", "feet", "shield"});
    int i;
    for (i = 0; i < sizeof(slots); i++) {
        object e = query_equip(slots[i]);
        if (e && e->id(arg)) {
            unequip_slot(slots[i]);
            write("你脫下了 " + e->query_short() + "。\n");
            return 1;
        }
    }
    write("你沒有裝備叫「" + arg + "」的東西。\n");
    return 1;
}

// ── 狀態指令 ──────────────────────────────────────────────
int do_score(string arg) {
    write("╔══════════════════════════════╗\n");
    write("║  角色：" + name + "\n");
    write("╠══════════════════════════════╣\n");
    write("║  等級：" + sprintf("%d", level) +
          "    經驗：" + sprintf("%d", exp) + "/" + sprintf("%d", exp_to_next) + "\n");
    write("║  HP：" + sprintf("%d", hp) + "/" + sprintf("%d", max_hp) +
          "    MP：" + sprintf("%d", mp) + "/" + sprintf("%d", max_mp) + "\n");
    write("║  ATK：" + sprintf("%d", attack) +
          "    DEF：" + sprintf("%d", defence) +
          "    金幣：" + sprintf("%d", gold) + "\n");
    write("╠══════════════════════════════╣\n");
    write("║  STR:" + sprintf("%3d", stat_str) +
          "  DEX:" + sprintf("%3d", stat_dex) +
          "  INT:" + sprintf("%3d", stat_int) + "\n");
    write("║  CON:" + sprintf("%3d", stat_con) +
          "  WIS:" + sprintf("%3d", stat_wis) +
          "  CHA:" + sprintf("%3d", stat_cha) + "\n");
    write("╠══════════════════════════════╣\n");
    write("║  武器：" + (equip_weapon ? equip_weapon->query_short() : "（無）") + "\n");
    write("║  頭盔：" + (equip_head   ? equip_head->query_short()   : "（無）") + "\n");
    write("║  護甲：" + (equip_body   ? equip_body->query_short()   : "（無）") + "\n");
    write("╚══════════════════════════════╝\n");
    return 1;
}

// ── 社交指令 ──────────────────────────────────────────────
int do_say_cmd(string arg) {
    if (!arg) { write("說什麼？\n"); return 1; }
    write("你說：「" + arg + "」\n");
    say(query_name() + " 說：「" + arg + "」\n");
    return 1;
}

int do_emote(string arg) {
    if (!arg) { write("做什麼動作？\n"); return 1; }
    string msg = query_name() + " " + arg + "\n";
    write(msg);
    say(msg);
    return 1;
}

// ── 名字指令 ──────────────────────────────────────────────
int do_name(string arg) {
    if (!arg) { write("你的名字是：" + name + "\n"); return 1; }
    string old = name;
    set_name(arg);
    write("你的名字改為：" + arg + "\n");
    say(old + " 改名為 " + arg + " 了。\n");
    return 1;
}

// ── 離開指令 ──────────────────────────────────────────────
int do_quit(string arg) {
    write("再見，" + name + "！你化為一道光消逝了...\n");
    say(name + " 離開了遊戲。\n");
    destruct(this_object());
    return 1;
}

// ── 幫助指令 ──────────────────────────────────────────────
int do_help(string arg) {
    write("╔══════════════════════════════════════╗\n");
    write("║            指令說明                  ║\n");
    write("╠══════════════════════════════════════╣\n");
    write("║ 移動：north/south/east/west/up/down  ║\n");
    write("║ 查看：look [目標]  examine [目標]    ║\n");
    write("║ 物品：get/drop/wear/wield/remove     ║\n");
    write("║ 背包：inventory (i)                  ║\n");
    write("║ 狀態：score / status                 ║\n");
    write("║ 戰鬥：kill <目標>  flee  skills      ║\n");
    write("║ 技能：fireball <目標>  heal          ║\n");
    write("║ 社交：say <訊息>  emote <動作>       ║\n");
    write("║ 系統：name <名字>  quit              ║\n");
    write("╚══════════════════════════════════════╝\n");
    return 1;
}

int process_input(string arg) {
    write("什麼？（輸入 help 查看指令）\n");
    return 0;
}
