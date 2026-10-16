// /secure/skill_d.c
// 技能守護進程 (Skill Daemon)

#include "/include/ansi.h"

mapping skill_list;

inherit "/std/object";

void create() {
    ::create();
    skill_list = ([
        "unarmed":      ([ "name": "拳腳功夫",       "type": "combat",  "max_level": 100 ]),
        "sword":        ([ "name": "基本劍法",       "type": "combat",  "max_level": 100 ]),
        "dodge":        ([ "name": "基本閃避",       "type": "combat",  "max_level": 100 ]),
        "parry":        ([ "name": "基本招架",       "type": "combat",  "max_level": 100 ]),
        "magic":        ([ "name": "基本魔法",       "type": "magic",   "max_level": 100 ]),
        "alchemy":      ([ "name": "煉金術",         "type": "craft",   "max_level": 100 ]),
        "forging":      ([ "name": "鍛造術",         "type": "craft",   "max_level": 100 ]),
        "taming":       ([ "name": "馴獸術",         "type": "special", "max_level": 100 ]),
        // 🚀 新手村五大出身專屬初級調息心法 (上限 Lv.10)
        "dream_sleep":  ([ "name": "睡夢大法(初級)", "type": "force",   "bg": "beggar",    "max_level": 10 ]),
        "still_heart":  ([ "name": "止心大法(初級)", "type": "force",   "bg": "daoist",    "max_level": 10 ]),
        "crazy_forge":  ([ "name": "瘋魔打鐵法(初級)", "type": "force", "bg": "smith",     "max_level": 10 ]),
        "herb_breathe": ([ "name": "百草吐納法(初級)", "type": "force", "bg": "herbalist", "max_level": 10 ]),
        "beast_breath": ([ "name": "山林龜息法(初級)", "type": "force", "bg": "hunter",    "max_level": 10 ])
    ]);
}

string resolve_skill_id(string input) {
    if (!input || input == "") return "";
    input = trim(input);
    if (skill_list[input]) return input;

    if (input == "睡夢大法" || input == "睡夢大法(初級)" || input == "睡夢") return "dream_sleep";
    if (input == "止心大法" || input == "止心大法(初級)" || input == "止心") return "still_heart";
    if (input == "瘋魔打鐵法" || input == "瘋魔打鐵法(初級)" || input == "瘋魔打鐵") return "crazy_forge";
    if (input == "百草吐納法" || input == "百草吐納法(初級)" || input == "百草吐納") return "herb_breathe";
    if (input == "山林龜息法" || input == "山林龜息法(初級)" || input == "龜息法") return "beast_breath";

    foreach (string sid in keys(skill_list)) {
        if (skill_list[sid]["name"] == input) return sid;
    }
    return input;
}

string query_skill_name(string sid) {
    if (skill_list[sid]) return skill_list[sid]["name"];
    return sid;
}

string query_skill_type(string sid) {
    if (skill_list[sid]) return skill_list[sid]["type"];
    return "other";
}

int query_max_level(string sid) {
    if (skill_list[sid] && skill_list[sid]["max_level"]) return skill_list[sid]["max_level"];
    return 100;
}

// 升級所需經驗值公式：(等級+1)^2 * 10
int query_upgrade_exp(int level) {
    return (level + 1) * (level + 1) * 10;
}

// 檢查是否升級
void check_upgrade(object me, string sid) {
    mapping skills = me->query_skills();
    if (!skills || !skills[sid]) return;

    int level = skills[sid]["level"];
    int exp   = skills[sid]["exp"];
    int req   = query_upgrade_exp(level);
    int max_lv = query_max_level(sid);

    if (level >= max_lv) {
        if (exp > req) skills[sid]["exp"] = req;
        return;
    }

    while (exp >= req && level < max_lv) {
        exp -= req;
        level++;
        req = query_upgrade_exp(level);
        
        tell_object(me, "$HIY$✨ 你的『" + query_skill_name(sid) + "』進步了！現在是等級 " + level + "。\n$NOR$");
        me->set_skill(sid, level);
        me->update_quest_progress(sid, "exp", exp);
        
        // 更新 exp (set_skill 只有設 level，我們直接改 mapping 內部)
        skills[sid]["exp"] = exp;
    }
}

// 傳授新手初級心法入門 (等級 1 並自動 enable)
int grant_starter_force(object me, string sid) {
    if (!me || !skill_list[sid]) return 0;
    string req_bg = skill_list[sid]["bg"];
    if (req_bg && me->query("background") != req_bg) {
        write(YEL "這門『" + query_skill_name(sid) + "』講究獨特的身世根底與生活習性，與你的路數並不契合。\n" NOR);
        return 0;
    }
    if (me->query_skill(sid) <= 0) {
        me->set_skill(sid, 1);
        if (!me->query("enabled_force")) {
            me->set("enabled_force", sid);
        }
        tell_object(me, HIY "\n✨【心法領悟】你成功領悟了獨門初級心法『" + query_skill_name(sid) + "』（等級 1）！\n" NOR);
        tell_object(me, HIG "（系統已將『" + query_skill_name(sid) + "』設為當前運轉心法，日後輸入 breathe / tuna / 吐納 / 凝神 / 調息 / 冥想 / 打坐 / 靜坐 即可運功恢復並提升熟練度；亦可用 enable 指令檢視或切換心法）\n\n" NOR);
        me->save();
        return 1;
    }
    return 0;
}

// 學習技能邏輯 (消耗潛能)
int learn_skill(object me, string sid, int amount) {
    sid = resolve_skill_id(sid);
    if (!skill_list[sid]) {
        write("沒有這種技能。\n");
        return 0;
    }

    string req_bg = skill_list[sid]["bg"];
    if (req_bg && me->query("background") != req_bg) {
        write(YEL "這門『" + query_skill_name(sid) + "』講究獨特的身世根底，你並非該出身，強行修習有害無益。\n" NOR);
        return 0;
    }

    int my_lv = me->query_skill(sid);
    int max_lv = query_max_level(sid);
    if (my_lv >= max_lv) {
        write("你的『" + query_skill_name(sid) + "』已達初級圓滿之境（等級 " + max_lv + "），需待日後踏入更高境界方能突破。\n");
        return 0;
    }

    // 初次學習初級心法若尚未入門 (Lv 0)，可直接獲傳入門 Lv 1
    if (my_lv <= 0 && skill_list[sid]["type"] == "force") {
        return grant_starter_force(me, sid);
    }

    int pot = me->query_potential();
    if (pot < amount) {
        write("你的潛能不足 (需要 " + amount + " 點潛能，目前擁有 " + pot + " 點)。\n");
        return 0;
    }

    // 學習效率受悟性 (int) 影響
    int gain = amount * (10 + me->query_stat("int")) / 10;
    
    me->gain_potential(-amount);
    me->improve_skill(sid, gain);
    
    write("你消耗了 " + amount + " 點潛能，對『" + query_skill_name(sid) + "』有了新的領悟。\n");
    return 1;
}

mapping query_all_skills() { return skill_list; }
