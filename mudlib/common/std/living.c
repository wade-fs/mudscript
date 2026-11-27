// std/living.c - 所有活物（玩家、NPC）的通用基底類別 (World-Agnostic)
// 移除特定小說硬編碼背景或六維限制，保留通用屬性容器

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/container.c";
inherit "/std/interactive.c";

// ── 基本資料 ─────────────────────────────────────────────
string  race;
int     level;
int     exp;
int     exp_to_next;
int     money_balance;  // 貨幣（以最小單位計）
int     potential;      // 潛能點數
mapping skills;         // ([ "id": ([ "level": 1, "exp": 0 ]) ])

// ── 屬性（通用六維，可被世界層覆寫語義）────────────────────
int     stat_str;   // 力量
int     stat_con;   // 體質
int     stat_int;   // 智力
int     stat_spi;   // 精神
int     stat_dex;   // 敏捷
int     stat_per;   // 感知

// ── 動態三柱 ─────────────────────────────────────────────
int     max_hp;
int     hp;
int     max_mp;
int     mp;
int     max_sp;
int     sp;
int     attack;
int     defence;

// ── 裝備欄位 ─────────────────────────────────────────────
object  equip_weapon;
object  equip_head;
object  equip_body;
object  equip_hands;
object  equip_feet;
object  equip_shield;

// ── 狀態旗標 ─────────────────────────────────────────────
int     in_combat;
object  combat_target;
int     is_dead;

// ── 組隊 ─────────────────────────────────────────────────
object  leader;
object *followers;

int is_living() { return 1; }

void recalc_stats() {
    max_hp = 50 + stat_con * 5 + level * 10;
    max_mp = 20 + stat_spi * 3 + level * 5;
    max_sp = 30 + stat_dex * 2 + level * 5;
    attack  = stat_str * 2 + level * 3;
    defence = stat_con + level * 2;
    if (hp > max_hp) hp = max_hp;
    if (mp > max_mp) mp = max_mp;
    if (sp > max_sp) sp = max_sp;
}

void create() {
    ::create();
    name       = "無名氏";
    level      = 1;
    exp        = 0;
    exp_to_next = BASE_EXP_PER_LV;

    stat_str = 10; stat_con = 10;
    stat_int = 10; stat_spi = 10;
    stat_dex = 10; stat_per = 10;

    in_combat     = 0;
    combat_target = 0;
    is_dead       = 0;
    money_balance = 0;
    potential     = 0;
    skills        = ([]);
    followers     = ({});

    recalc_stats();
    hp = max_hp;
    mp = max_mp;
    sp = max_sp;
}

// ── 指令處理 ────────────────────────────────────────────
int process_input(string input) {
    string verb, arg;
    input = trim(input);
    if (!input || input == "") return 0;

    int sp_idx = strsrch(input, " ");
    if (sp_idx < 0) {
        verb = input;
        arg = 0;
    } else {
        verb = substr(input, 0, sp_idx);
        arg = substr(input, sp_idx + 1, strlen(input) - sp_idx - 1);
    }

    object cmd_d = load_object("/secure/command_d.c");
    if (cmd_d) {
        return cmd_d->execute(this_object(), verb, arg);
    }
    return 0;
}

// ── 設定與查詢 ──────────────────────────────────────────
void set_level(int v)        { level = v; recalc_stats(); }
int  query_level()           { return level; }
void set_race(string r)      { race = r; }
string query_race()          { return race; }
int  query_hp()              { return hp; }
int  query_max_hp()          { return max_hp; }
int  query_mp()              { return mp; }
int  query_max_mp()          { return max_mp; }
int  query_sp()              { return sp; }
int  query_max_sp()          { return max_sp; }
void set_hp(int v)           { if (v > max_hp) v = max_hp; if (v < 0) v = 0; hp = v; }
void set_mp(int v)           { if (v > max_mp) v = max_mp; if (v < 0) v = 0; mp = v; }
void set_sp(int v)           { if (v > max_sp) v = max_sp; if (v < 0) v = 0; sp = v; }
void add_hp(int v)           { set_hp(hp + v); }
void add_mp(int v)           { set_mp(mp + v); }
void add_sp(int v)           { set_sp(sp + v); }
int  query_attack()          { return attack; }
int  query_defence()         { return defence; }
int  query_money()           { return money_balance; }
void set_money(int v)        { money_balance = v; }
void add_money(int v)        { money_balance += v; }
int  query_exp()             { return exp; }
int  query_in_combat()       { return in_combat; }
void set_in_combat(int v)    { in_combat = v; }
object query_combat_target() { return combat_target; }
void set_combat_target(object ob) { combat_target = ob; }
int  query_dead()            { return is_dead; }

void set_stat_str(int v)     { stat_str = v; recalc_stats(); }
void set_stat_con(int v)     { stat_con = v; recalc_stats(); }
void set_stat_int(int v)     { stat_int = v; recalc_stats(); }
void set_stat_spi(int v)     { stat_spi = v; recalc_stats(); }
void set_stat_dex(int v)     { stat_dex = v; recalc_stats(); }
void set_stat_per(int v)     { stat_per = v; recalc_stats(); }

int  query_stat_str()        { return stat_str; }
int  query_stat_con()        { return stat_con; }
int  query_stat_int()        { return stat_int; }
int  query_stat_spi()        { return stat_spi; }
int  query_stat_dex()        { return stat_dex; }
int  query_stat_per()        { return stat_per; }

// ── 技能 ────────────────────────────────────────────────
mapping query_skills()       { return skills; }
int query_skill_level(string sid) {
    if (!skills || !skills[sid]) return 0;
    return skills[sid]["level"] ? skills[sid]["level"] : 0;
}

// ── 經驗值 ──────────────────────────────────────────────
void gain_exp(int amount) {
    if (amount <= 0) return;
    exp += amount;
    while (exp >= exp_to_next) {
        exp -= exp_to_next;
        level++;
        exp_to_next = BASE_EXP_PER_LV * level;
        recalc_stats();
        hp = max_hp;
        mp = max_mp;
        sp = max_sp;
        write("{GRN}【升級】你升到了 " + level + " 級！{NOR}\n");
    }
}
