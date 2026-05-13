// std/living.c - 所有活物（玩家、NPC）的基底類別

#include "/include/config.h"

inherit "/std/container.c";
inherit "/std/interactive.c";

// ── 基本資料 ─────────────────────────────────────────────
string  name;
string  race;
int     level;
int     exp;
int     exp_to_next;
int     gold;
mapping skills;

// ── 六圍屬性 ─────────────────────────────────────────────
int     stat_str;   // 力量
int     stat_dex;   // 敏捷
int     stat_int;   // 智力
int     stat_con;   //體魄
int     stat_wis;   // 智慧
int     stat_cha;   // 魅力

// ── 戰鬥屬性（由 recalc_stats 計算） ─────────────────────
int     max_hp;
int     hp;
int     max_mp;
int     mp;
int     attack;     // 攻擊力
int     defence;    // 防禦力

// ── 裝備欄位 ─────────────────────────────────────────────
object  equip_weapon;
object  equip_head;
object  equip_body;
object  equip_hands;
object  equip_feet;
object  equip_shield;

// ── 狀態旗標 ─────────────────────────────────────────────
int     in_combat;     // 是否正在戰鬥
object  combat_target; // 當前戰鬥目標
int     is_dead;

void create() {
    ::create();
    name       = "無名氏";
    level      = 1;
    exp        = 0;
    exp_to_next= BASE_EXP_PER_LV;

    stat_str = 10;  stat_dex = 10;
    stat_int = 10;  stat_con = 10;
    stat_wis = 10;  stat_cha = 10;

    in_combat      = 0;
    combat_target  = 0;
    is_dead        = 0;
    gold           = 0;
    skills         = ([]);

    recalc_stats();
    enable_commands();
}

// 判斷物件是否可以進入生物的背包 (生物預設不允許其他生物進入)
int can_receive(object ob) {
    if (!ob) return 0;
    if (living(ob)) return 0; // 不允許生物進入另一個生物
    return ::can_receive(ob); // 呼叫父類別的容量檢查
}

// 判斷是否為生物
int is_living() { return 1; }

// ── 重算衍生屬性 ──────────────────────────────────────────
void recalc_stats() {
    max_hp  = stat_con * MAX_HP_PER_CON + level * 5;
    max_mp  = stat_int * 5 + stat_wis * 3 + level * 3;
    attack  = BASE_ATTACK  + stat_str * 2;
    defence = BASE_DEFENCE + stat_con;

    // 套上武器加成
    if (equip_weapon) {
        attack = attack + equip_weapon->query_attack();
    }
    // 套上防具加成
    int armour_def = 0;
    if (equip_head)   { armour_def = armour_def + equip_head->query_defence(); }
    if (equip_body)   { armour_def = armour_def + equip_body->query_defence(); }
    if (equip_hands)  { armour_def = armour_def + equip_hands->query_defence(); }
    if (equip_feet)   { armour_def = armour_def + equip_feet->query_defence(); }
    if (equip_shield) { armour_def = armour_def + equip_shield->query_defence(); }
    defence = defence + armour_def;

    // 確保 HP/MP 不超上限
    if (hp > max_hp) { hp = max_hp; }
    if (mp > max_mp) { mp = max_mp; }
}

// ── 設定 / 查詢 ────────────────────────────────────────────
void set_name(string n) {
    name = n;
}
string query_name()       { return name; }
void set_race(string r)   { race = r; }
string query_race()       { return race; }
void set_level(int l)     { level = l; }
int query_level()         { return level; }
int query_exp()           { return exp; }
void set_hp(int v)        { hp = v; }
int query_hp()            { return hp; }
int query_max_hp()        { return max_hp; }
void set_mp(int v)        { mp = v; }
int query_mp()            { return mp; }
int query_max_mp()        { return max_mp; }
int query_attack()        { return attack; }
int query_defence()       { return defence; }
int query_stat(string s)  {
    if (s == STAT_STR) { return stat_str; }
    if (s == STAT_DEX) { return stat_dex; }
    if (s == STAT_INT) { return stat_int; }
    if (s == STAT_CON) { return stat_con; }
    if (s == STAT_WIS) { return stat_wis; }
    if (s == STAT_CHA) { return stat_cha; }
    return 0;
}
string query_display_name() {
    string id = query_key_id();
    if (id && id != "" && id != query_name()) {
        return query_name() + "(" + id + ")";
    }
    return query_name();
}

void set_stat(string s, int v) {
    if (s == STAT_STR) { stat_str = v; }
    if (s == STAT_DEX) { stat_dex = v; }
    if (s == STAT_INT) { stat_int = v; }
    if (s == STAT_CON) { stat_con = v; }
    if (s == STAT_WIS) { stat_wis = v; }
    if (s == STAT_CHA) { stat_cha = v; }
    recalc_stats();
}

// ── HP / MP 操作 ───────────────────────────────────────────
int heal_hp(int amount) {
    hp = hp + amount;
    if (hp > max_hp) { hp = max_hp; }
    return hp;
}

int take_damage(int amount) {
    hp = hp - amount;
    if (hp < 0) { hp = 0; }
    return hp;
}

int use_mp(int amount) {
    if (mp < amount) { return 0; }
    mp = mp - amount;
    return 1;
}

// ── 裝備管理 ───────────────────────────────────────────────
int equip(object item) {
    if (!item) { return 0; }
    string slot = item->query_slot();

    if (slot == SLOT_WEAPON) { equip_weapon = item; }
    else if (slot == SLOT_HEAD)   { equip_head   = item; }
    else if (slot == SLOT_BODY)   { equip_body   = item; }
    else if (slot == SLOT_HANDS)  { equip_hands  = item; }
    else if (slot == SLOT_FEET)   { equip_feet   = item; }
    else if (slot == SLOT_SHIELD) { equip_shield = item; }
    else { return 0; }

    recalc_stats();
    return 1;
}

int unequip_slot(string slot) {
    if (slot == SLOT_WEAPON) { equip_weapon = 0; }
    else if (slot == SLOT_HEAD)   { equip_head   = 0; }
    else if (slot == SLOT_BODY)   { equip_body   = 0; }
    else if (slot == SLOT_HANDS)  { equip_hands  = 0; }
    else if (slot == SLOT_FEET)   { equip_feet   = 0; }
    else if (slot == SLOT_SHIELD) { equip_shield = 0; }
    else { return 0; }
    recalc_stats();
    return 1;
}

object query_equip(string slot) {
    if (slot == SLOT_WEAPON) { return equip_weapon; }
    if (slot == SLOT_HEAD)   { return equip_head; }
    if (slot == SLOT_BODY)   { return equip_body; }
    if (slot == SLOT_HANDS)  { return equip_hands; }
    if (slot == SLOT_FEET)   { return equip_feet; }
    if (slot == SLOT_SHIELD) { return equip_shield; }
    return 0;
}

// ── 經驗值與升級 ───────────────────────────────────────────
void gain_exp(int amount) {
    exp = exp + amount;
    write("你獲得了 " + sprintf("%d", amount) + " 點經驗值。\n");

    while (exp >= exp_to_next && level < MAX_LEVEL) {
        exp = exp - exp_to_next;
        level = level + 1;
        exp_to_next = exp_to_next + BASE_EXP_PER_LV * level / 2;

        // 升級獎勵：每升一級六圍各 +1
        stat_str = stat_str + 1;
        stat_dex = stat_dex + 1;
        stat_int = stat_int + 1;
        stat_con = stat_con + 1;
        stat_wis = stat_wis + 1;
        stat_cha = stat_cha + 1;
        recalc_stats();
        hp = max_hp;
        mp = max_mp;

        write("\n✨ 恭喜升級！你現在是 " + sprintf("%d", level) + " 級了！\n");
        write("六圍屬性各 +1，HP/MP 完全恢復。\n\n");
        say(name + " 升級了！現在是 " + sprintf("%d", level) + " 級。\n");
    }
}

// ── 死亡處理 ───────────────────────────────────────────────
void die() {
    if (is_dead) { return; }
    is_dead     = 1;
    in_combat   = 0;
    combat_target = 0;
    set_heart_beat(0);
    on_death();
}

void on_death() {
    // 子類別覆寫此函式來定義死亡行為
    write(name + " 倒下了！\n");
}

// ── 戰鬥基礎 ─────────────────────────────────────────────
void stop_combat() {
    in_combat = 0;
    combat_target = 0;
}

void attacked_by(object attacker) {
    if (is_dead) return;
    
    object env = environment(this_object());
    if (env && env->query_no_combat()) {
        if (attacker) tell_object(attacker, "這裡禁止戰鬥！\n");
        return;
    }

    if (!in_combat) {
        in_combat     = 1;
        combat_target = attacker;
    }
}

// ── 金幣與技能 ───────────────────────────────────────────
void add_gold(int g) { gold += g; }
void gain_gold(int g) { gold += g; }
int query_gold() { return gold; }

void set_skill(string s, int v) {
    if (!skills) skills = ([]);
    skills[s] = v;
}

int query_skill(string s) {
    if (!skills) return 0;
    return skills[s];
}

mapping query_skills() { return skills; }

// catch_tell：活物收到訊息，預設不做任何事（子類別可覆寫）
void catch_tell(string msg) {
}
