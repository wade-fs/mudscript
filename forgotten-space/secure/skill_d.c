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
        "beast_breath": ([ "name": "山林龜息法(初級)", "type": "force", "bg": "hunter",    "max_level": 10 ]),

        // 🌟 Tier 1 【法】道途技能域 (Skill Lv.31 ~ 100，資源池: sen)
        "dao_tuna":      ([ "name": "基礎吐納",       "type": "force",   "path": "fa", "cost_pool": "sen", "domain": "meditation", "class": "dao_initiate", "max_level": 100 ]),
        "dao_jiefa":     ([ "name": "借法印訣",       "type": "magic",   "path": "fa", "cost_pool": "sen", "domain": "spell",      "class": "dao_initiate", "max_level": 100 ]),
        "dao_observing": ([ "name": "觀星望氣",       "type": "magic",   "path": "fa", "cost_pool": "sen", "domain": "divination", "class": "dao_initiate", "max_level": 100 ]),
        "dao_fuling":    ([ "name": "縛靈法印",       "type": "magic",   "path": "fa", "cost_pool": "sen", "domain": "divination", "class": "dao_initiate", "max_level": 100 ]),
        "dao_fuzhen":    ([ "name": "硃砂鎮煞符",     "type": "magic",   "path": "fa", "cost_pool": "sen", "domain": "talisman",   "class": "dao_initiate", "max_level": 100 ]),
        "dao_fudun":     ([ "name": "清風定神符",     "type": "magic",   "path": "fa", "cost_pool": "sen", "domain": "talisman",   "class": "dao_initiate", "max_level": 100 ]),
        "dao_jinglei":   ([ "name": "驚雷破障印",     "type": "magic",   "path": "fa", "cost_pool": "sen", "domain": "talisman",   "class": "dao_initiate", "max_level": 100 ]),

        // 🌟 Tier 1 【力】道途技能域 (Skill Lv.31 ~ 100，資源池: kee)
        "wu_cuigu":      ([ "name": "鐵砂淬骨",       "type": "force",   "path": "li", "cost_pool": "kee", "domain": "physique",   "class": "wu_initiate",  "max_level": 100 ]),
        "wu_fuhu":       ([ "name": "伏虎重拳",       "type": "combat",  "path": "li", "cost_pool": "kee", "domain": "brawling",   "class": "wu_initiate",  "max_level": 100 ]),
        "wu_kaishan":    ([ "name": "開山劈嶽",       "type": "combat",  "path": "li", "cost_pool": "kee", "domain": "vanguard",   "class": "wu_initiate",  "max_level": 100 ]),
        "wu_qixue":      ([ "name": "氣血如爐",       "type": "force",   "path": "li", "cost_pool": "kee", "domain": "vanguard",   "class": "wu_initiate",  "max_level": 100 ]),
        "wu_panshi":     ([ "name": "盤石樁功",       "type": "force",   "path": "li", "cost_pool": "kee", "domain": "guard",      "class": "wu_initiate",  "max_level": 100 ]),
        "wu_pijia":      ([ "name": "披甲回天",       "type": "combat",  "path": "li", "cost_pool": "kee", "domain": "guard",      "class": "wu_initiate",  "max_level": 100 ]),
        "wu_gong_sheshi":([ "name": "開弦貫石",       "type": "combat",  "path": "li", "cost_pool": "kee", "domain": "archery",    "class": "wu_initiate",  "max_level": 100 ]),
        "wu_gong_yingshi":([ "name": "鷹揚穿雲",      "type": "combat",  "path": "li", "cost_pool": "kee", "domain": "archery",    "class": "wu_initiate",  "max_level": 100 ]),

        // 🌟 Tier 1 【物】道途技能域 (Skill Lv.31 ~ 100，資源池: sp)
        "gong_analysis": ([ "name": "物性辨析",       "type": "craft",   "path": "wu", "cost_pool": "sp",  "domain": "analysis",   "class": "gong_initiate","max_level": 100 ]),
        "gong_qiaojin":  ([ "name": "百工巧勁",       "type": "combat",  "path": "wu", "cost_pool": "sp",  "domain": "forging",    "class": "gong_initiate","max_level": 100 ]),
        "gong_yingli":   ([ "name": "應力破點",       "type": "combat",  "path": "wu", "cost_pool": "sp",  "domain": "forging",    "class": "gong_initiate","max_level": 100 ]),
        "gong_cuihuo":   ([ "name": "淬火披堅",       "type": "craft",   "path": "wu", "cost_pool": "sp",  "domain": "forging",    "class": "gong_initiate","max_level": 100 ]),
        "gong_xingzhen": ([ "name": "辨症行針",       "type": "craft",   "path": "wu", "cost_pool": "sp",  "domain": "medicine",   "class": "gong_initiate","max_level": 100 ]),
        "gong_fengdu":   ([ "name": "雄黃封毒散",     "type": "special", "path": "wu", "cost_pool": "sp",  "domain": "medicine",   "class": "gong_initiate","max_level": 100 ]),
        "gong_jiguan":   ([ "name": "地弩穿心機",     "type": "special", "path": "wu", "cost_pool": "sp",  "domain": "mechanism",  "class": "gong_initiate","max_level": 100 ]),
        "gong_feizhua":  ([ "name": "飛爪滑輪鎖",     "type": "special", "path": "wu", "cost_pool": "sp",  "domain": "mechanism",  "class": "gong_initiate","max_level": 100 ])
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

// 傳授一階道途啟蒙基礎技能 (等級 31)，並同步授予對應之初始資格與組織歸屬
// 注意：僅啟蒙兩項入門根基，絕不自動灌頂整條技能樹！
void grant_starter_class_skills(object me, string class_id) {
    if (!me || !class_id) return;
    if (class_id == "dao_initiate") {
        me->set_path("fa");
        me->join_organization("org_xuandaosi", "清虛外門記名經生");
        me->set_org_branch("org_xuandaosi", "hq");
        me->set_hq_registered("org_xuandaosi", 1);
        me->grant_qualification_by("lic_diviner", 1, "金石府宣道司");
        if (me->query_skill("dao_tuna") < 31) me->set_skill("dao_tuna", 31);
        if (me->query_skill("dao_jiefa") < 31) me->set_skill("dao_jiefa", 31);
        tell_object(me, HIG "【道途啟蒙】你確立【法】道根基，獲發宣道司受牒度牒，領悟入門『基礎吐納』(Lv 31) 與『借法印訣』(Lv 31)！（其餘分支法術須另行隨師修習）\n" NOR);
    } else if (class_id == "wu_initiate") {
        me->set_path("li");
        me->join_organization("org_bafang", "八方武館外門武卒");
        me->set_org_branch("org_bafang", "hq");
        me->set_hq_registered("org_bafang", 1);
        me->grant_qualification_by("lic_escort_guard", 1, "八方行省武館總舵");
        if (me->query_skill("wu_cuigu") < 31) me->set_skill("wu_cuigu", 31);
        if (me->query_skill("wu_fuhu") < 31) me->set_skill("wu_fuhu", 31);
        tell_object(me, HIG "【道途啟蒙】你確立【力】道根基，獲發八方黑鐵腰牌，領悟入門『鐵砂淬骨』(Lv 31) 與『伏虎重拳』(Lv 31)！（其餘猛將／衛士／重弓絕技須另行隨師修習）\n" NOR);
    } else if (class_id == "gong_initiate") {
        me->set_path("wu");
        me->join_organization("org_baigong", "百工總會註冊學徒");
        me->set_org_branch("org_baigong", "hq");
        me->set_hq_registered("org_baigong", 1);
        me->grant_qualification_by("lic_master_artisan", 1, "府城百工總會匠籍處");
        if (me->query_skill("gong_analysis") < 31) me->set_skill("gong_analysis", 31);
        if (me->query_skill("gong_qiaojin") < 31) me->set_skill("gong_qiaojin", 31);
        tell_object(me, HIG "【道途啟蒙】你確立【物】道根基，獲發百工匠籍，領悟入門『物性辨析』(Lv 31) 與『百工巧勁』(Lv 31)！（其餘鍛造／藥道／機巧專精須另行隨師修習）\n" NOR);
    }
}

mapping query_all_skills() { return skill_list; }

// ── 四維解耦檢驗模型：道途 (Path) ≠ 能力 (Skill) ≠ 資格 (Qualification) ≠ 組織 (Organization) ──

mapping QUALIFICATION_DEFS = ([
    "lic_apothecary":     ([ "name": "杏林坐堂行醫資格", "issuer": "杏林醫館／採百草分堂", "desc": "合法於城內坐堂開立官制猛藥與調配管制毒囊之執業資格" ]),
    "lic_diviner":        ([ "name": "大乾觀象受牒度牒", "issuer": "金石府宣道司",         "desc": "於內城絕靈法網下合法施展借法、觀象與繪符之豁免憑證" ]),
    "lic_master_artisan": ([ "name": "百工正式匠籍",     "issuer": "府城百工總會匠籍處",   "desc": "合法申領烈礬官管赤銅、硝石配額並調用千錘地爐之憑證" ]),
    "lic_escort_guard":   ([ "name": "八方黑鐵腰牌",     "issuer": "八方行省武館／車馬院", "desc": "合法披甲持重兵過四關、簽生死狀上擂台及承接跨縣押鏢之憑證" ]),
    "lic_broker":         ([ "name": "通寶牙人信印",     "issuer": "通寶當鋪／金石商會",   "desc": "合法進入六縣專材大宗盤口議價與調閱跨縣信用底單之憑證" ])
]);

mapping ORGANIZATION_DEFS = ([
    "org_xuandaosi": ([ "name": "金石府宣道司",   "facilities": ({ "/d/city/west/dao_observatory.c", "/d/city/west/dao_quiet.c" }) ]),
    "org_bafang":    ([ "name": "八方行省武館",   "facilities": ({ "/d/city/east/wu_plaza.c", "/d/city/east/wu_armory.c", "/d/city/east/wu_arena.c" }) ]),
    "org_baigong":   ([ "name": "府城百工總會",   "facilities": ({ "/d/city/north/gong_forge.c", "/d/city/north/gong_wood.c", "/d/city/north/gong_alchemy.c" }) ]),
    "org_xinglin":   ([ "name": "杏林醫館",       "facilities": ({ "/d/city/center/clinic.c" }) ]),
    "org_shanghui":  ([ "name": "金石商會",       "facilities": ({ "/d/city/south/caravan_yard.c", "/d/city/south/warehouse_shang.c" }) ])
]);

mapping query_qualification_def(string lic_id) {
    return QUALIFICATION_DEFS[lic_id];
}

mapping query_organization_def(string org_id) {
    return ORGANIZATION_DEFS[org_id];
}

// 檢驗專業行為：將「實際能力 (Skill)」與「合法執業資格 (Qualification)」徹底拆開判定
mapping check_professional_action(object me, string action_type) {
    if (!me) return ([ "can_do": 0, "legal": 0, "status": "invalid" ]);

    if (action_type == "prescribe_medicine") {
        // 醫道開方：需要實際醫理手藝 (gong_analysis 或 gong_xingzhen) 與 杏林行醫資格 (lic_apothecary)
        int has_skill = (me->query_skill("gong_analysis") >= 31 || me->query_skill("gong_xingzhen") >= 31 || me->query_skill("alchemy") >= 20);
        int has_lic   = (me->query_qualification("lic_apothecary") > 0);

        if (has_skill && !has_lic) {
            return ([
                "can_do": 1,
                "legal": 0,
                "status": "unlicensed_skill",
                "msg": "你雖通曉辨藥行針之術（具備實際能力），但未取得【杏林坐堂行醫資格】，私自開立官制猛藥屬無照私醫，藥行拒發管制毒囊且府衙將予究辦！"
            ]);
        }
        if (!has_skill && has_lic) {
            return ([
                "can_do": 0,
                "legal": 1,
                "status": "licensed_no_skill",
                "msg": "你雖持有【杏林坐堂行醫資格】（具備合法資格），卻未真正修習辨藥與行針手藝，面對病患脈象無從下手！"
            ]);
        }
        if (has_skill && has_lic) {
            return ([
                "can_do": 1,
                "legal": 1,
                "status": "qualified_practitioner",
                "msg": "你兼具醫道手藝與合法行醫資格，順利開立處方並調配官制藥劑。"
            ]);
        }
        return ([ "can_do": 0, "legal": 0, "status": "none", "msg": "你既無醫理手藝，亦無行醫資格。" ]);
    }

    if (action_type == "cast_in_city") {
        int has_skill = (me->query_skill("dao_jiefa") >= 31 || me->query_skill("magic") >= 20);
        int has_lic   = (me->query_qualification("lic_diviner") > 0);
        if (has_skill && !has_lic) {
            return ([
                "can_do": 1,
                "legal": 0,
                "status": "unlicensed_skill",
                "msg": "你雖修得借法印訣，但未持宣道司【大乾觀象受牒度牒】，在內城絕靈法網下強行施法將立即觸發『破法犯』緝捕！"
            ]);
        }
        if (!has_skill && has_lic) {
            return ([ "can_do": 0, "legal": 1, "status": "licensed_no_skill", "msg": "你雖持宣道司度牒，卻尚未修成借法印訣。" ]);
        }
        if (has_skill && has_lic) {
            return ([ "can_do": 1, "legal": 1, "status": "qualified_practitioner", "msg": "度牒靈紋與絕靈法網共鳴豁免，你合法引動周虛靈機施展印訣。" ]);
        }
        return ([ "can_do": 0, "legal": 0, "status": "none", "msg": "你既無法道修為，亦無受牒度牒。" ]);
    }

    if (action_type == "requisition_restricted_ore") {
        int has_skill = (me->query_skill("gong_cuihuo") >= 31 || me->query_skill("forging") >= 20);
        int has_lic   = (me->query_qualification("lic_master_artisan") > 0);
        if (has_skill && !has_lic) {
            return ([
                "can_do": 1,
                "legal": 0,
                "status": "unlicensed_skill",
                "msg": "你雖精湛鍛造手藝，但未登記【百工正式匠籍】，司匠簿吏拒絕批核烈礬管制赤銅與硝石配額！"
            ]);
        }
        if (!has_skill && has_lic) {
            return ([ "can_do": 0, "legal": 1, "status": "licensed_no_skill", "msg": "你雖掛名百工匠籍獲准領料，卻無淬火鍛造之實作能力。" ]);
        }
        if (has_skill && has_lic) {
            return ([ "can_do": 1, "legal": 1, "status": "qualified_practitioner", "msg": "憑百工匠籍核銷批件，你順利調用千錘地爐與官管赤銅進行鍛造。" ]);
        }
        return ([ "can_do": 0, "legal": 0, "status": "none", "msg": "你既無鍛造手藝，亦無百工匠籍。" ]);
    }

    return ([ "can_do": 0, "legal": 0, "status": "unknown_action" ]);
}

// ── P0-2 & OPEN-02(B)：六縣多起點地方傳承與初階資格等效認證矩陣 (6縣 × 3道途 = 18處) ──
mapping COUNTY_QUALIFICATION_ENTRIES = ([
    "qinghe": ([
        "fa": ([
            "inst": "定神靈植道觀（宣道司外派）",
            "lic_id": "lic_diviner",
            "org_id": "org_xuandaosi",
            "branch_id": "branch_qinghe_dao",
            "rank": "青河靈植觀受牒經生",
            "skills": ({ "dao_tuna", "dao_jiefa" }),
            "room": "/d/counties/qinghe/herb_shrine.c",
            "examiner": "雲松道人"
        ]),
        "li": ([
            "inst": "青河水師營校場（八方武館協訓）",
            "lic_id": "lic_escort_guard",
            "org_id": "org_bafang",
            "branch_id": "branch_qinghe_wu",
            "rank": "青河水陸護航武卒",
            "skills": ({ "wu_cuigu", "wu_fuhu" }),
            "room": "/d/counties/qinghe/drill_ground.c",
            "examiner": "江萬濤"
        ]),
        "wu": ([
            "inst": "青河洗藥總坊（採百草分堂青河分號）",
            "lic_id": "lic_apothecary",
            "org_id": "org_xinglin",
            "branch_id": "branch_qinghe_yi",
            "rank": "青河採百草坐堂藥師",
            "skills": ({ "gong_analysis", "gong_qiaojin" }),
            "room": "/d/counties/qinghe/herb_mill.c",
            "examiner": "蘇明月"
        ])
    ]),
    "liefan": ([
        "fa": ([
            "inst": "烈礬鎮煞火祠（宣道司外派）",
            "lic_id": "lic_diviner",
            "org_id": "org_xuandaosi",
            "branch_id": "branch_liefan_dao",
            "rank": "烈礬火祠觀火經生",
            "skills": ({ "dao_tuna", "dao_jiefa" }),
            "room": "/d/counties/liefan/fire_shrine.c",
            "examiner": "赤陽道長"
        ]),
        "li": ([
            "inst": "烈礬護礦武館（八方武館分舵）",
            "lic_id": "lic_escort_guard",
            "org_id": "org_bafang",
            "branch_id": "branch_liefan_wu",
            "rank": "烈礬護礦黑鐵武卒",
            "skills": ({ "wu_cuigu", "wu_fuhu" }),
            "room": "/d/counties/liefan/mine_guard_hall.c",
            "examiner": "雷震山"
        ]),
        "wu": ([
            "inst": "烈礬百工冶煉分舵（百工總會分舵）",
            "lic_id": "lic_master_artisan",
            "org_id": "org_baigong",
            "branch_id": "branch_liefan_gong",
            "rank": "烈礬百工冶煉匠徒",
            "skills": ({ "gong_analysis", "gong_qiaojin" }),
            "room": "/d/counties/liefan/smelting_branch.c",
            "examiner": "歐陽炎"
        ])
    ]),
    "panmu": ([
        "fa": ([
            "inst": "盤木山神廟（宣道司外派駐點）",
            "lic_id": "lic_diviner",
            "org_id": "org_xuandaosi",
            "branch_id": "branch_panmu_dao",
            "rank": "盤木山祠望氣經生",
            "skills": ({ "dao_tuna", "dao_jiefa" }),
            "room": "/d/counties/panmu/mountain_shrine.c",
            "examiner": "古木真人"
        ]),
        "li": ([
            "inst": "盤木巡山獵武堂（八方武館分舵）",
            "lic_id": "lic_escort_guard",
            "org_id": "org_bafang",
            "branch_id": "branch_panmu_wu",
            "rank": "盤木巡山黑鐵獵卒",
            "skills": ({ "wu_cuigu", "wu_fuhu" }),
            "room": "/d/counties/panmu/hunter_lodge.c",
            "examiner": "周獵虎"
        ]),
        "wu": ([
            "inst": "天工木作工棚（百工機巧分舵）",
            "lic_id": "lic_master_artisan",
            "org_id": "org_baigong",
            "branch_id": "branch_panmu_gong",
            "rank": "盤木天工木作匠徒",
            "skills": ({ "gong_analysis", "gong_qiaojin" }),
            "room": "/d/counties/panmu/carpentry_shed.c",
            "examiner": "魯長林"
        ])
    ]),
    "zhenfeng": ([
        "fa": ([
            "inst": "鎮風測風祭壇（宣道司邊塞觀象所）",
            "lic_id": "lic_diviner",
            "org_id": "org_xuandaosi",
            "branch_id": "branch_zhenfeng_dao",
            "rank": "鎮風邊塞測風經生",
            "skills": ({ "dao_tuna", "dao_jiefa" }),
            "room": "/d/counties/zhenfeng/wind_altar.c",
            "examiner": "凌風子"
        ]),
        "li": ([
            "inst": "八方武館邊關分舵（車馬院北塞總站）",
            "lic_id": "lic_escort_guard",
            "org_id": "org_bafang",
            "branch_id": "branch_zhenfeng_wu",
            "rank": "鎮風邊關黑鐵武卒",
            "skills": ({ "wu_cuigu", "wu_fuhu" }),
            "room": "/d/counties/zhenfeng/bafang_garrison.c",
            "examiner": "秦烈風"
        ]),
        "wu": ([
            "inst": "鎮風軍械修造所（百工皮革與弓弩分舵）",
            "lic_id": "lic_master_artisan",
            "org_id": "org_baigong",
            "branch_id": "branch_zhenfeng_gong",
            "rank": "鎮風軍械皮甲匠徒",
            "skills": ({ "gong_analysis", "gong_qiaojin" }),
            "room": "/d/counties/zhenfeng/tannery.c",
            "examiner": "溫鐵衣"
        ])
    ]),
    "zhuoshui": ([
        "fa": ([
            "inst": "濁水鎮水祠（宣道司辟瘴觀）",
            "lic_id": "lic_diviner",
            "org_id": "org_xuandaosi",
            "branch_id": "branch_zhuoshui_dao",
            "rank": "濁水鎮煞辟瘴經生",
            "skills": ({ "dao_tuna", "dao_jiefa" }),
            "room": "/d/counties/zhuoshui/miasma_shrine.c",
            "examiner": "滄浪道人"
        ]),
        "li": ([
            "inst": "濁水護澤武館（八方武館水路分舵）",
            "lic_id": "lic_escort_guard",
            "org_id": "org_bafang",
            "branch_id": "branch_zhuoshui_wu",
            "rank": "濁水浮橋黑鐵護衛",
            "skills": ({ "wu_cuigu", "wu_fuhu" }),
            "room": "/d/counties/zhuoshui/water_fort.c",
            "examiner": "彭鐵槳"
        ]),
        "wu": ([
            "inst": "濁水百草毒理棚（採百草分堂毒理分號）",
            "lic_id": "lic_apothecary",
            "org_id": "org_xinglin",
            "branch_id": "branch_zhuoshui_yi",
            "rank": "濁水百草辨毒藥師",
            "skills": ({ "gong_analysis", "gong_qiaojin" }),
            "room": "/d/counties/zhuoshui/venom_shed.c",
            "examiner": "白青竹"
        ])
    ]),
    "zhongshi": ([
        "fa": ([
            "inst": "重石測脈亭（宣道司地脈勘驗所）",
            "lic_id": "lic_diviner",
            "org_id": "org_xuandaosi",
            "branch_id": "branch_zhongshi_dao",
            "rank": "重石測脈觀象經生",
            "skills": ({ "dao_tuna", "dao_jiefa" }),
            "room": "/d/counties/zhongshi/leyline_pavilion.c",
            "examiner": "石璣道人"
        ]),
        "li": ([
            "inst": "重石穿山寨分館（八方武館力士堂）",
            "lic_id": "lic_escort_guard",
            "org_id": "org_bafang",
            "branch_id": "branch_zhongshi_wu",
            "rank": "重石開山黑鐵力士",
            "skills": ({ "wu_cuigu", "wu_fuhu" }),
            "room": "/d/counties/zhongshi/crusher_hall.c",
            "examiner": "石霸天"
        ]),
        "wu": ([
            "inst": "重石石作總坊（百工石作與生鐵分舵）",
            "lic_id": "lic_master_artisan",
            "org_id": "org_baigong",
            "branch_id": "branch_zhongshi_gong",
            "rank": "重石百工石作匠徒",
            "skills": ({ "gong_analysis", "gong_qiaojin" }),
            "room": "/d/counties/zhongshi/stone_guild.c",
            "examiner": "韓千鈞"
        ])
    ])
]);

int is_county_branch_facility(string org_id, string room_path) {
    if (!org_id || !room_path) return 0;
    foreach (string cid in keys(COUNTY_QUALIFICATION_ENTRIES)) {
        mapping paths = COUNTY_QUALIFICATION_ENTRIES[cid];
        foreach (string p in keys(paths)) {
            mapping entry = paths[p];
            if (entry["org_id"] == org_id && entry["room"] == room_path) {
                return 1;
            }
        }
    }
    return 0;
}

// 檢驗組織設施存取權：加入組織提供場地存取權，但絕不等於自動掌握該組織整條技能樹；
// 地方分舵成員可直接存取分舵場地，但調用府城總舵核心設施須先完成「掛單轉錄」(register_at_headquarters)
mapping check_org_facility_access(object me, string org_id, string room_path) {
    if (!me || !ORGANIZATION_DEFS[org_id]) return ([ "access": 0, "msg": "未知組織" ]);
    string rank = me->query_org_rank(org_id);
    int is_member = (rank && rank != "");
    string *facs = ORGANIZATION_DEFS[org_id]["facilities"];
    int is_hq_fac = (member_array(room_path, facs) != -1);
    int is_branch_fac = is_county_branch_facility(org_id, room_path);

    // 計算角色在該組織對應道途已學會的高階分支技能數（驗證加入行會 != 自動掌握整條技能樹）
    int advanced_count = 0;
    if (org_id == "org_baigong") {
        if (me->query_skill("gong_yingli") > 0) advanced_count++;
        if (me->query_skill("gong_cuihuo") > 0) advanced_count++;
        if (me->query_skill("gong_xingzhen") > 0) advanced_count++;
        if (me->query_skill("gong_fengdu") > 0) advanced_count++;
        if (me->query_skill("gong_jiguan") > 0) advanced_count++;
        if (me->query_skill("gong_feizhua") > 0) advanced_count++;
    } else if (org_id == "org_bafang") {
        if (me->query_skill("wu_kaishan") > 0) advanced_count++;
        if (me->query_skill("wu_qixue") > 0) advanced_count++;
        if (me->query_skill("wu_panshi") > 0) advanced_count++;
        if (me->query_skill("wu_pijia") > 0) advanced_count++;
        if (me->query_skill("wu_gong_sheshi") > 0) advanced_count++;
        if (me->query_skill("wu_gong_yingshi") > 0) advanced_count++;
    } else if (org_id == "org_xuandaosi") {
        if (me->query_skill("dao_observing") > 0) advanced_count++;
        if (me->query_skill("dao_fuling") > 0) advanced_count++;
        if (me->query_skill("dao_fuzhen") > 0) advanced_count++;
        if (me->query_skill("dao_fudun") > 0) advanced_count++;
        if (me->query_skill("dao_jinglei") > 0) advanced_count++;
    }

    if (!is_member) {
        return ([
            "access": 0,
            "status": "not_member",
            "org_rank": "",
            "advanced_skills_unlocked": advanced_count,
            "msg": "你並非該組織成員，無權擅用內部專屬設施。"
        ]);
    }

    string branch = me->query_org_branch(org_id);
    if (is_hq_fac && branch != "" && branch != "hq" && !me->query_hq_registered(org_id)) {
        return ([
            "access": 0,
            "status": "requires_hq_registration",
            "org_rank": rank,
            "branch_id": branch,
            "advanced_skills_unlocked": advanced_count,
            "msg": "你持有地方分舵資格（" + rank + "），須先於府城總舵完成『掛單轉錄』(register_at_headquarters)，方可調用府城核心工坊／觀星台／武庫設施。"
        ]);
    }

    int can_access = (is_hq_fac || is_branch_fac) ? 1 : 0;
    return ([
        "access": can_access,
        "status": is_branch_fac ? "branch_facility_access" : (is_hq_fac ? "hq_facility_access" : "unlisted_facility"),
        "org_rank": rank,
        "branch_id": branch,
        "advanced_skills_unlocked": advanced_count,
        "msg": "你身為" + ORGANIZATION_DEFS[org_id]["name"] + "成員（" + rank + "），享有內部工坊／校場設施存取權。"
    ]);
}

mapping check_county_qualification_equivalence(string county_id, string path) {
    if (!county_id || !COUNTY_QUALIFICATION_ENTRIES[county_id] || !COUNTY_QUALIFICATION_ENTRIES[county_id][path]) {
        return ([ "equivalent": 0, "canon_rule": "RULE", "msg": "未知的縣份或道途" ]);
    }
    mapping entry = COUNTY_QUALIFICATION_ENTRIES[county_id][path];
    return ([
        "equivalent": 1,
        "canon_rule": "RULE",
        "local_institution": entry["inst"],
        "lic_id": entry["lic_id"],
        "org_id": entry["org_id"],
        "branch_id": entry["branch_id"],
        "rank_title": entry["rank"],
        "starter_skills": entry["skills"],
        "room": entry["room"],
        "examiner": entry["examiner"],
        "narrative_distinction": "【世界規則】六縣地方機構可核發與金石府城等效之初階資格與師承入口；第二卷五位主角集中赴府城係因背負卷一跨縣證據鏈與生死約定之主動劇情選擇，並非世界唯一流程。"
    ]);
}

// 六縣地方分舵初階資格考取與啟蒙發放：核發與府城完全相同之 lic_* 資格 ID，但標註地方核發機構與分舵歸屬
int grant_county_initiation(object me, string county_id, string path) {
    if (!me || !county_id || !COUNTY_QUALIFICATION_ENTRIES[county_id] || !COUNTY_QUALIFICATION_ENTRIES[county_id][path]) {
        return 0;
    }
    mapping entry = COUNTY_QUALIFICATION_ENTRIES[county_id][path];
    string class_id = "gong_initiate";
    if (path == "fa") class_id = "dao_initiate";
    else if (path == "li") class_id = "wu_initiate";

    me->set_path(path);
    me->set("class", class_id);
    me->set("origin_county", county_id);
    me->grant_qualification_by(entry["lic_id"], 1, entry["inst"]);
    me->join_organization(entry["org_id"], entry["rank"]);
    me->set_org_branch(entry["org_id"], entry["branch_id"]);
    me->set_hq_registered(entry["org_id"], 0);

    string *sks = entry["skills"];
    for (int i = 0; i < sizeof(sks); i++) {
        string sk = sks[i];
        if (me->query_skill(sk) < 31) me->set_skill(sk, 31);
    }

    tell_object(me, HIG "【六縣地方啟蒙】你通過「" + entry["inst"] + "」主考官" + entry["examiner"] + "之初階核驗，獲授『" + entry["rank"] + "』身分與等效執業資格，並習得基礎入門技藝 (Lv 31)！\n" NOR);
    return 1;
}

// 地方分舵成員赴金石府城總舵辦理「掛單轉錄」，解鎖府城總部核心設施使用權
mapping register_at_headquarters(object me, string org_id) {
    if (!me || !org_id || !ORGANIZATION_DEFS[org_id]) {
        return ([ "registered": 0, "msg": "未知的組織。" ]);
    }
    string rank = me->query_org_rank(org_id);
    if (!rank || rank == "") {
        return ([ "registered": 0, "msg": "你尚未取得該組織之地方分舵或總舵資格，無法辦理掛單轉錄。" ]);
    }
    me->set_hq_registered(org_id, 1);
    return ([
        "registered": 1,
        "org_id": org_id,
        "branch_id": me->query_org_branch(org_id),
        "org_rank": rank,
        "msg": "總舵主事核驗你的地方分舵文牒與印信無誤，已為你完成府城總舵『掛單轉錄』，即日起可依序申請使用府城總部核心設施。"
    ]);
}

// ── 壓力測試節點 4 (Ch.79–82)：卷尾破境與 Tier 1→Tier 2 門檻四維分離 ──
// 將「技能滿值(Lv.100)」、「社會專業資格」、「生命層次破障(Lv.50)」與「名山宗門考核令」嚴格拆開
mapping evaluate_tier1_completion_state(object me) {
    if (!me) return ([ "status": "invalid" ]);

    // 1. 檢查是否有任一核心道途技能達 Lv.100 (技能圓滿)
    int max_skill_lv = 0;
    mapping sks = me->query_skills();
    if (mapp(sks)) {
        foreach (string sid in keys(sks)) {
            if (mapp(sks[sid]) && sks[sid]["level"] > max_skill_lv) {
                max_skill_lv = sks[sid]["level"];
            }
        }
    }
    int has_skill_mastery = (max_skill_lv >= 100) ? 1 : 0;

    // 2. 檢查是否具備地方社會專業資格 (Qualification)
    mapping quals = me->query_qualifications();
    int has_social_qualification = (mapp(quals) && sizeof(keys(quals)) > 0) ? 1 : 0;

    // 3. 檢查是否完成 Lv.50 肉身／心神破障 (Breakthrough)
    int has_realm_breakthrough = (me->query("level") >= 50 || me->query("tier1_breakthrough") > 0) ? 1 : 0;

    // 4. 檢查是否獲發 Tier 2 名山宗門外門考核令 (Admission Token)
    int has_tier2_token = (me->query("tier2_admission_token") > 0 || present("sect trial token", me)) ? 1 : 0;

    return ([
        "skill_mastery": has_skill_mastery,
        "max_skill_level": max_skill_lv,
        "social_qualification": has_social_qualification,
        "realm_breakthrough": has_realm_breakthrough,
        "tier2_admission_token": has_tier2_token,
        "ready_for_tier2_trial": (has_realm_breakthrough && has_social_qualification && has_tier2_token) ? 1 : 0,
        "msg": "Tier 1 結算四維分離：破境 (Lv.50) 僅代表肉身／心神容器突破凡胎，不等於自動習得滿級技藝 (Lv.100) 或取得社會執業資格，亦僅是報名 Tier 2 名山宗門大考的門檻而非直接成為宗門真傳。"
    ]);
}
