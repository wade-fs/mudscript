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
int     max_hp;     // 氣血上限 (kee)
int     hp;         // 當前氣血 (kee)
int     max_mp;     // 神識上限 (sen)
int     mp;         // 當前神識 (sen)
int     max_sp;     // 精力上限 (sp)
int     sp;         // 當前精力 (sp)
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
object  active_pet;    // 🚀 新增：當前寵物
int     is_riding;     // 🚀 新增：正在騎乘

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
    active_pet     = 0;
    is_riding      = 0;

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

// ── 指令處理 ──────────────────────────────────────────
int process_input(string input) {
    string verb, arg;
    
    input = trim(input);
    if (!input || input == "") return 0;

    // 解析動詞與參數
    int sp = strsrch(input, " ");
    if (sp < 0) {
        verb = input;
        arg = 0;
    } else {
        verb = substr(input, 0, sp);
        arg = substr(input, sp + 1, strlen(input) - sp - 1);
    }
    
    // 呼叫指令守護進程執行全域指令
    object cmd_d = load_object("/secure/command_d.c");
    if (cmd_d) {
        return cmd_d->execute(this_object(), verb, arg);
    }
    return 0;
}

// ── 重算衍生屬性 ──────────────────────────────────────────
void recalc_stats() {
    max_hp  = (stat_str + stat_con) * 10 + level * 10;
    max_mp  = (stat_int + stat_wis) * 10 + level * 10;
    max_sp  = (stat_dex + stat_cha) * 10 + level * 10;
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

    // 確保三柱狀態不超上限
    if (hp > max_hp) { hp = max_hp; }
    if (mp > max_mp) { mp = max_mp; }
    if (sp > max_sp) { sp = max_sp; }

    // 依臂力/力量計算生物負重上限 (基礎 20kg + 每點臂力 3kg)
    set_max_weight(20000 + stat_str * 3000);
    set_max_items(30);
}

// ── 設定 / 查詢 ────────────────────────────────────────────
void set_race(string r)   { race = r; }
string query_race()       { return race; }
void set_level(int l)     { level = l; }
int query_level()         { return level; }
int query_exp()           { return exp; }
int query_exp_to_next()   { return exp_to_next; }
void set_hp(int v)        { hp = v; }
int query_hp()            { return hp; }
int query_max_hp()        { return max_hp; }
void set_mp(int v)        { mp = v; }
int query_mp()            { return mp; }
int query_max_mp()        { return max_mp; }
void set_sp(int v)        { sp = v; }
int query_sp()            { return sp; }
int query_max_sp()        { return max_sp; }
int query_attack()        { return attack; }
int query_defence()       { return defence; }

mixed query(string prop) {
    if (prop == "level") return level;
    if (prop == "kee" || prop == "hp" || prop == "qi") return hp;
    if (prop == "sen" || prop == "mp" || prop == "shen") return mp;
    if (prop == "sp" || prop == "jing" || prop == "gin") return sp;
    if (prop == "max_kee" || prop == "max_hp" || prop == "max_qi") return max_hp;
    if (prop == "max_sen" || prop == "max_mp" || prop == "max_shen") return max_mp;
    if (prop == "max_sp" || prop == "max_jing" || prop == "max_gin") return max_sp;
    if (prop == "str") return stat_str;
    if (prop == "con") return stat_con;
    if (prop == "int") return stat_int;
    if (prop == "spi" || prop == "wis") return stat_wis;
    if (prop == "dex") return stat_dex;
    if (prop == "per" || prop == "cha") return stat_cha;
    return ::query(prop);
}

void add(string prop, mixed val) {
    if (prop == "kee" || prop == "hp" || prop == "qi") {
        hp += val;
        if (hp > max_hp) hp = max_hp;
        if (hp < 0) hp = 0;
        return;
    }
    if (prop == "sen" || prop == "mp" || prop == "shen") {
        mp += val;
        if (mp > max_mp) mp = max_mp;
        if (mp < 0) mp = 0;
        return;
    }
    if (prop == "sp" || prop == "jing" || prop == "gin") {
        sp += val;
        if (sp > max_sp) sp = max_sp;
        if (sp < 0) sp = 0;
        return;
    }
    if (prop == "exp") {
        if (val > 0) gain_exp(val);
        return;
    }
    if (prop == "str") { stat_str += val; recalc_stats(); return; }
    if (prop == "con") { stat_con += val; recalc_stats(); return; }
    if (prop == "int") { stat_int += val; recalc_stats(); return; }
    if (prop == "spi" || prop == "wis") { stat_wis += val; recalc_stats(); return; }
    if (prop == "dex") { stat_dex += val; recalc_stats(); return; }
    if (prop == "per" || prop == "cha") { stat_cha += val; recalc_stats(); return; }
    ::add(prop, val);
}

int query_stat(string s)  {
    if (s == STAT_STR || s == "str") { return stat_str; }
    if (s == STAT_DEX || s == "dex") { return stat_dex; }
    if (s == STAT_INT || s == "int") { return stat_int; }
    if (s == STAT_CON || s == "con") { return stat_con; }
    if (s == STAT_WIS || s == "spi" || s == "wis") { return stat_wis; }
    if (s == STAT_CHA || s == "per" || s == "cha") { return stat_cha; }
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
        res += "$HIY$ <騎乘中: " + active_pet->query_name() + ">$NOR$";
    }
    return res;
}

void set_stat(string s, int v) {
    if (s == STAT_STR || s == "str") { stat_str = v; }
    if (s == STAT_DEX || s == "dex") { stat_dex = v; }
    if (s == STAT_INT || s == "int") { stat_int = v; }
    if (s == STAT_CON || s == "con") { stat_con = v; }
    if (s == STAT_WIS || s == "spi" || s == "wis") { stat_wis = v; }
    if (s == STAT_CHA || s == "per" || s == "cha") { stat_cha = v; }
    recalc_stats();
}

int query_growth_affinity(string stat) {
    return 100;
}

string normalize_stat_key(string s) {
    if (s == "wis") return "spi";
    if (s == "cha") return "per";
    return s;
}

string query_stat_cn_name(string s) {
    s = normalize_stat_key(s);
    if (s == "str") return "臂力";
    if (s == "con") return "根骨";
    if (s == "int") return "悟性";
    if (s == "spi") return "靈性";
    if (s == "dex") return "靈巧";
    if (s == "per") return "感知";
    return s;
}

int query_stat_train(string s) {
    s = normalize_stat_key(s);
    return ::query("stat_train/" + s);
}

int query_stat_train_req(string s) {
    int cur = query_stat(s);
    if (cur < 1) cur = 1;
    return cur * 50;
}

// 🚀 屬性鍛鍊進度系統：結合身世親和度累積鍛鍊度，滿門檻 (當前屬性*50) 才 +1
int train_stat(string stat, int base_pts) {
    stat = normalize_stat_key(stat);
    int cur = query_stat(stat);
    if (cur < 1) cur = 1;
    int req = cur * 50;

    int aff = this_object()->query_growth_affinity(stat);
    if (aff <= 0) aff = 100;
    int gain = base_pts * aff / 100;
    if (gain < 1) gain = 1;

    int prog = ::query("stat_train/" + stat) + gain;
    string sname = query_stat_cn_name(stat);

    if (prog >= req) {
        prog -= req;
        ::set("stat_train/" + stat, prog);
        set_stat(stat, cur + 1);
        tell_object(this_object(), HIY "✨【破障提升】經過千錘百鍊的積累，你的「" + sname + "」正式突破至 " + sprintf("%d", cur + 1) + " 點！\n" NOR);
        return 1;
    } else {
        ::set("stat_train/" + stat, prog);
        tell_object(this_object(), CYN "  （" + sname + "鍛鍊度 +" + sprintf("%d", gain) + " [" + sprintf("%d", prog) + "/" + sprintf("%d", req) + "]，身世親和 " + sprintf("%d", aff) + "%）\n" NOR);
        return 0;
    }
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
            tell_object(me, "$HIY$你騎著 " + active_pet->query_name() + " 抵達了目的地。\n$NOR$");
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

// ── 隱藏飲食飽脹度系統 (單純隨心跳時間消化) ───────────────────
int consume_drink(int amount) {
    int cur = ::query("water_fullness");
    if (cur >= 90) {
        tell_object(this_object(), YEL "你肚子裡已經灌滿了水，脹得直打水嗝，得過一陣子消化後才能再喝。\n" NOR);
        return 0;
    }
    cur += amount;
    if (cur > 100) cur = 100;
    ::set("water_fullness", cur);
    return 1;
}

int consume_food(int amount) {
    int cur = ::query("food_fullness");
    if (cur >= 90) {
        tell_object(this_object(), YEL "你已經吃得太飽了，肚子撐得慌，得過一陣子消化後才能再吃。\n" NOR);
        return 0;
    }
    cur += amount;
    if (cur > 100) cur = 100;
    ::set("food_fullness", cur);
    return 1;
}

void digest_food_water(int amount) {
    int w = ::query("water_fullness");
    if (w > 0) {
        w -= amount;
        if (w < 0) w = 0;
        ::set("water_fullness", w);
    }
    int f = ::query("food_fullness");
    if (f > 0) {
        f -= amount;
        if (f < 0) f = 0;
        ::set("food_fullness", f);
    }
}

// ── 經驗值與升級 ───────────────────────────────────────────
void gain_exp(int amount) {
    exp = exp + amount;
    int pot_gain = amount / 4;
    if (pot_gain < 1) pot_gain = 1;
    potential += pot_gain;
    write("你獲得了 " + sprintf("%d", amount) + " 點經驗值（潛能 +" + sprintf("%d", pot_gain) + "）。\n");

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
        sp = max_sp;

        write("\n✨ 恭喜升級！你現在是 " + sprintf("%d", level) + " 級了！\n");
        write("六圍屬性各 +1，氣血/神識/精力完全恢復。\n\n");
        say(name + " 升級了！現在是 " + sprintf("%d", level) + " 級。\n");
    }
}

// ── 死亡處理 ───────────────────────────────────────────────
void die() {
    if (is_dead) { return; }

    object me = this_object();
    object env = environment(me);
    
    if (userp(me)) {
        tell_object(me, "$HIR$\n👻 你感覺到靈魂正在脫離肉體... 你死了。\n\n$NOR$");
    }
    say("$HIR$" + query_name() + " 的呼吸停止了，靈魂飄向了另一個世界。\n$NOR$");

    // 1. 產生屍體
    object corpse = clone_object("/std/corpse.c");
    if (corpse) {
        corpse->set_owner(query_name());
        if (env) {
            move_object(corpse, env);
        } else {
            // 如果是在測試或特殊情況下死亡且無環境，則先不移動屍體
        }

        // 🚀 掉落物品 (排除 no_drop)
        object *inv = all_inventory(me);
        foreach (object ob in inv) {
            if (ob && !ob->query_no_drop()) {
                move_object(ob, corpse);
            }
        }

        // 🚀 掉落金錢 (身上所有銅幣)
        int drop_cash = query_money();
        if (drop_cash > 0) {
            add_money(-drop_cash);
            object money_ob = clone_object("/std/object.c");
            if (money_ob) {
                money_ob->set_name("銅幣袋");
                money_ob->set_short("$YEL$一袋銅幣 (" + drop_cash + ")$NOR$");
                money_ob->set_id(({"money bag", "bag", "錢袋"}));
                money_ob->set_money_value(drop_cash);
                move_object(money_ob, corpse);
            }
        }

        // 2. 🚀 死亡懲罰計算 (僅對玩家生效)
        if (userp(me)) {
            // 損失當前等級升級所需總額的 5%
            int lost_exp = exp_to_next / 20; 
            int lost_pot = potential / 5; // 損失潛能的 20%
            if (lost_exp < 1) lost_exp = 1;
            
            int lv_down = 0;
            if (random(100) < 20) lv_down = 1;

            // 紀錄懲罰資料，用於跑屍恢復
            mapping penalty = ([
                "owner": me->get_id(),
                "exp": lost_exp,
                "pot": lost_pot,
                "level_down": lv_down
            ]);
            corpse->set_penalty_data(penalty);

            // 執行懲罰
            exp -= lost_exp;
            if (exp < 0) exp = 0;
            potential -= lost_pot;
            if (lv_down && level > 1) {
                level--;
                tell_object(me, "$HIR$你的等級下降了！現在是等級 " + level + "。\n$NOR$");
            }

            // 🚀 技能熟練度下降 (所有學過的技能隨機掉 1~5% 熟練度)
            if (mapp(skills)) {
                mixed ks = keys(skills);
                foreach (string sid in ks) {
                    int s_exp = skills[sid]["exp"];
                    skills[sid]["exp"] = s_exp * 95 / 100;
                }
            }
        }
    }

    // 3. 🚀 清除紅名 (死亡贖罪)
    if (pk_score > 0) {
        pk_score = 0;
        pk_timer = 0;
        write("$HIG$你的罪孽在死亡中得到了洗贖，你不再是紅名了。\n$NOR$");
    }

    is_dead = 1;
    in_combat = 0;
    combat_target = 0;
    set_heart_beat(0);
    
    recalc_stats();
    me->save();

    // 4. 傳送到起始點或靈魂神殿
    call_out("revive", 2);
}

void revive() {
    is_dead = 0;
    hp = max_hp / 10; // 復活時只有 10% 狀態
    mp = max_mp / 10;
    sp = max_sp / 10;
    set_heart_beat(1);
    
    string start_path = START_ROOM;
    if (userp(this_object())) {
        start_path = this_object()->query_start_room();
    }
    
    object start = load_object(start_path);
    if (start) {
        move_object(start);
        write("$HIW$你在祈禱室緩緩睜開雙眼，感覺身體非常虛弱。\n$NOR$");
        start->look_room(this_object());
    }
    this_object()->save();
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
    if (cg > 0) res += "$HIY$" + to_string(cg) + " " + _t("coin_cool_gold") + " $NOR$";
    if (g  > 0) res += "$HIY$" + to_string(g) + " " + _t("coin_gold") + " $NOR$";
    if (s  > 0) res += "$WHT$" + to_string(s) + " " + _t("coin_silver") + " $NOR$";
    if (c  > 0) res += "$YEL$" + to_string(c) + " " + _t("coin_copper") + " $NOR$";
    
    if (res == "") return "$YEL$0 " + _t("coin_copper") + "$NOR$";
    return res;
}

// 取得無顏色標籤的貨幣字串 (用於 UI)
string query_money_plain() {
    int rem = money_balance;
    int cg = rem / COIN_COOL_GOLD;
    rem = rem % COIN_COOL_GOLD;
    int g  = rem / COIN_GOLD;
    rem = rem % COIN_GOLD;
    int s  = rem / COIN_SILVER;
    rem = rem % COIN_SILVER;
    int c  = rem;

    string res = "";
    if (cg > 0) res += to_string(cg) + " " + _t("coin_cool_gold") + " ";
    if (g  > 0) res += to_string(g)  + " " + _t("coin_gold") + " ";
    if (s  > 0) res += to_string(s)  + " " + _t("coin_silver") + " ";
    if (c  > 0) res += to_string(c)  + " " + _t("coin_copper") + " ";
    
    if (res == "") return "0 " + _t("coin_copper");
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
    
    int old_level = 0;
    mixed existing = skills[s];
    if (existing) {
        if (intp(existing)) old_level = existing;
        else old_level = existing["level"];
    }
    
    skills[s] = ([ "level": v, "exp": 0 ]);
}

int query_skill(string s) {
    if (!skills) return 0;
    mixed existing = skills[s];
    if (!existing) return 0;
    if (intp(existing)) return existing;
    return existing["level"];
}

int query_skill_exp(string s) {
    if (!skills) return 0;
    mixed existing = skills[s];
    if (!existing) return 0;
    if (intp(existing)) return 0;
    return existing["exp"];
}

void set_skill_level(string s, int v) {
    set_skill(s, v);
}

void improve_skill(string s, int v) {
    if (!skills) skills = ([]);
    
    int old_level = 0;
    int old_exp = 0;
    mixed existing = skills[s];
    if (existing) {
        if (intp(existing)) {
            old_level = existing;
        } else {
            old_level = existing["level"];
            old_exp = existing["exp"];
        }
    }

    skills[s] = ([ "level": old_level, "exp": old_exp + v ]);

    // 呼叫 Skill Daemon 判斷是否升級
    load_object("/secure/skill_d.c")->check_upgrade(this_object(), s);
}
mapping query_skills() { return skills; }

// catch_tell：活物收到訊息，預設不做任何事（子類別可覆寫）
void catch_tell(string msg) {
}
