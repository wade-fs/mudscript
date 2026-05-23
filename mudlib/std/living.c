// std/living.c - 所有活物（玩家、NPC）的基底類別

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/container.c";
inherit "/std/interactive.c";

// ── 基本資料 ─────────────────────────────────────────────
string  race;
int     level;
int     exp;
int     exp_to_next;
int     money_balance; // 🚀 變更：總財產 (以銅幣為單位)
int     potential; // 🚀 新增：潛能點數 (用於學習技能)
mapping skills;    // 格式變更：([ "id": ([ "level": 1, "exp": 0 ]) ])

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

// 🚀 新增：PK 系統
int     pk_score;      // PK 分數 (正值代表殺害無辜次數)
int     pk_timer;      // 紅名倒數計時 (Unix Time)

// 🚀 新增：組隊與跟隨
object  leader; 
object *followers;

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
    money_balance  = 0;
    potential      = 0;
    skills         = ([]);
    followers      = ({});

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

    // 🚀 新增：技能加成
    if (equip_weapon) {
        string w_type = equip_weapon->query_weapon_type();
        attack += query_skill(w_type);
        attack += equip_weapon->query_attack();
    } else {
        attack += query_skill("unarmed");
    }

    // 防禦加成 (閃避與招架)
    defence += query_skill("dodge") / 2;
    defence += query_skill("parry") / 2;

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
    string res = query_name();
    if (id && id != "" && id != query_name()) {
        res = query_name() + "(" + id + ")";
    }
    // 🚀 新增：騎乘狀態顯示
    if (is_riding && active_pet) {
        res += HIY(" <騎乘中: " + active_pet->query_name() + ">");
    }
    return res;
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

// ── 功能函式 ────────────────────────────────────────────
int move(mixed dest, string dir) {
    object me = this_object();
    object old_env = environment(me);
    
    move_object(dest);
    
    object new_env = environment(me);
    if (new_env == old_env) return 0; // 移動失敗

    // 🚀 處理寵物同步移動
    if (active_pet && environment(active_pet) == old_env) {
        active_pet->move_object(new_env);
        if (is_riding) {
            tell_object(me, HIY("你騎著 " + active_pet->query_name() + " 抵達了目的地。\n"));
        }
    }

    // 🚀 處理跟隨者
    object *f_list = me->query_followers();
    if (f_list && sizeof(f_list) > 0) {
        foreach (object f in f_list) {
            // 避免無限遞迴 (雖然正常情況下不會)
            if (!f || f == me || environment(f) != old_env) continue;
            
            tell_object(f, "你緊跟著 " + me->query_name() + " 往 " + dir + " 走了過去。\n");
            f->move(new_env, dir);
        }
    }
    
    return 1;
}

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

object query_combat_target() { return combat_target; }
void set_combat_target(object ob) { combat_target = ob; if (ob) in_combat = 1; else in_combat = 0; }

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

// ── 貨幣、金幣與技能 ───────────────────────────────────────────
void add_money(int v) { money_balance += v; if (money_balance < 0) money_balance = 0; }
void gain_money(int v) { money_balance += v; }
int query_money() { return money_balance; }

// 相容舊代碼 (1 金幣 = 10,000 銅幣)
void add_gold(int g) { add_money(g * COIN_GOLD); }
void gain_gold(int g) { add_money(g * COIN_GOLD); }
int query_gold() { return money_balance / COIN_GOLD; }

// 取得貨幣顯示字串
string query_money_string() {
    int rem = money_balance;
    int cg = rem / COIN_COOL_GOLD;
    rem = rem % COIN_COOL_GOLD;
    int g  = rem / COIN_GOLD;
    rem = rem % COIN_GOLD;
    int s  = rem / COIN_SILVER;
    rem = rem % COIN_SILVER;
    int c  = rem;

    string res = "";
    if (cg > 0) res += HIY(to_string(cg) + " 酷金幣 ");
    if (g  > 0) res += HIY(to_string(g)  + " 金幣 ");
    if (s  > 0) res += WHT(to_string(s)  + " 銀幣 ");
    if (c  > 0) res += YEL(to_string(c)  + " 銅幣 ");
    
    if (res == "") return YEL("0 銅幣");
    return res;
}

void gain_potential(int v) { potential += v; }
int query_potential() { return potential; }

// ── 組隊與跟隨介面 ─────────────────────────────────────────────
object  query_leader() { return leader; }
void    set_leader(object ob) { leader = ob; }
object *query_followers() { return followers; }
void    add_follower(object ob) { if (member_array(ob, followers) == -1) followers += ({ ob }); }
void    remove_follower(object ob) { followers -= ({ ob }); }

// ── PK 系統介面 ─────────────────────────────────────────────
int query_pk_score() { return pk_score; }
void add_pk_score(int v) { 
    pk_score += v; 
    if (pk_score < 0) pk_score = 0;
    if (v > 0) pk_timer = time() + 3600; // 每殺一人紅名維持一小時
}
int is_red_name() { 
    if (pk_score > 0) {
        if (time() > pk_timer) {
            // 這裡可以做緩慢下降逻辑，暫時簡單化：計時到就歸零
            pk_score = 0;
            return 0;
        }
        return 1;
    }
    return 0; 
}

// ── 技能管理介面 ──────────────────────────────────────────
void set_skill(string s, int v) {
    if (!skills) skills = ([]);
    if (!skills[s]) skills[s] = ([ "level": 0, "exp": 0 ]);
    skills[s]["level"] = v;
}

int query_skill(string s) {
    if (!skills || !skills[s]) return 0;
    return skills[s]["level"];
}

int query_skill_exp(string s) {
    if (!skills || !skills[s]) return 0;
    return skills[s]["exp"];
}

void improve_skill(string s, int v) {
    if (!skills) skills = ([]);
    if (!skills[s]) skills[s] = ([ "level": 0, "exp": 0 ]);
    
    skills[s]["exp"] += v;
    
    // 呼叫 Skill Daemon 判斷是否升級
    load_object("/secure/skill_d.c")->check_upgrade(this_object(), s);
}

mapping query_skills() { return skills; }

// catch_tell：活物收到訊息，預設不做任何事（子類別可覆寫）
void catch_tell(string msg) {
}
