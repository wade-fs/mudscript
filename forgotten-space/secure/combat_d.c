// /secure/combat_d.c
// 戰鬥守護進程 (Combat Daemon)
// 《遺忘的世界》(THE FORGOTTEN SPACE)
// 核心法則：
// 1. 三元力量（【力】li / 【法】fa / 【物】wu）與先天六維（str/con, int/spi, dex/per）
// 2. 三柱資源消耗（【力】燃氣血 kee、【法】耗神識 sen、【物】竭精力 sp）
// 3. 三角生剋（【力】剋【法】、【法】剋【物】、【物】剋【力】，克制方 +25% 威力，被克方 -15% 威力）
// 4. 金石內城絕靈法網檢核（無受牒度牒 lic_diviner 強行施展【法】道招式將遭法網反噬與威力折損）

#include "/include/ansi.h"
#include "/include/globals.h"

mapping skills;

inherit "/std/object";

void create() {
    ::create();
    skills = ([
        // ══════════════════════════════════════════════════════════
        // ── 【力】道途 (人即世界：燃氣血 kee，依賴 str / con) ──
        // ══════════════════════════════════════════════════════════
        "wu_fuhu": ([
            "name": "伏虎重拳",
            "type": "physical",
            "path": "li",
            "path_name": "【力】道",
            "cost_pool": "kee",
            "cost": 15,
            "level": 10,
            "msg": HIR "💥 你周身筋骨齊鳴，氣血如潮湧入雙拳，對 $target 轟出一記剛猛無匹的『$name』！\n" NOR,
            "apply_func": "skill_wu_fuhu"
        ]),
        "wu_kaishan": ([
            "name": "開山劈嶽",
            "type": "physical",
            "path": "li",
            "path_name": "【力】道",
            "cost_pool": "kee",
            "cost": 25,
            "level": 31,
            "msg": HIR "⚔️ 你暴喝一聲，雙臂青筋暴起，挾千鈞重勢對 $target 連環劈出兩記『$name』！\n" NOR,
            "apply_func": "skill_wu_kaishan"
        ]),
        "wu_qixue": ([
            "name": "氣血如爐",
            "type": "physical",
            "path": "li",
            "path_name": "【力】道",
            "cost_pool": "kee",
            "cost": 20,
            "level": 31,
            "msg": HIR "🔥 你催動『$name』，體內氣血化作狂暴烘爐，灼熱氣浪正面震向 $target 的神識與周身靈機！\n" NOR,
            "apply_func": "skill_wu_qixue"
        ]),
        "wu_gong_sheshi": ([
            "name": "開弦貫石",
            "type": "physical",
            "path": "li",
            "path_name": "【力】道",
            "cost_pool": "kee",
            "cost": 20,
            "level": 31,
            "msg": HIY "🏹 你滿挽重弓如滿月，渾身氣血灌注箭簇，一記『$name』破空貫向 $target！\n" NOR,
            "apply_func": "skill_wu_gong_sheshi"
        ]),
        "wu_pijia": ([
            "name": "披甲回天",
            "type": "support",
            "path": "li",
            "path_name": "【力】道",
            "cost_pool": "sp",
            "cost": 15,
            "level": 10,
            "msg": HIG "🛡️ 你沉腰坐馬運轉『$name』，周身氣血烘爐流轉，震散瘀血並強行振作生機。\n" NOR,
            "apply_func": "skill_wu_pijia"
        ]),

        // ══════════════════════════════════════════════════════════
        // ── 【法】道途 (世界即我：耗神識 sen，依賴 int / spi) ──
        // ══════════════════════════════════════════════════════════
        "dao_jiefa": ([
            "name": "借法印訣",
            "type": "magic",
            "path": "fa",
            "path_name": "【法】道",
            "cost_pool": "sen",
            "cost": 20,
            "level": 10,
            "msg": HIC "☯️ 你凝神掐動『$name』，引動周虛游離靈機化作一道離火玄光轟向 $target！\n" NOR,
            "apply_func": "skill_dao_jiefa"
        ]),
        "dao_fuzhen": ([
            "name": "硃砂鎮煞符",
            "type": "magic",
            "path": "fa",
            "path_name": "【法】道",
            "cost_pool": "sen",
            "cost": 25,
            "level": 31,
            "msg": HIY "📜 你指尖逼出精純神識點燃『$name』，赤紅符火化作鎮煞金印鎮向 $target！\n" NOR,
            "apply_func": "skill_dao_fuzhen"
        ]),
        "dao_jinglei": ([
            "name": "驚雷破障印",
            "type": "magic",
            "path": "fa",
            "path_name": "【法】道",
            "cost_pool": "sen",
            "cost": 35,
            "level": 31,
            "msg": HIB "⚡ 你雙手結出『$name』，引九天煌煌紫電劈落，雷霆靈機瞬間穿透 $target 的甲冑與機括！\n" NOR,
            "apply_func": "skill_dao_jinglei"
        ]),
        "dao_fudun": ([
            "name": "清風定神符",
            "type": "support",
            "path": "fa",
            "path_name": "【法】道",
            "cost_pool": "sen",
            "cost": 15,
            "level": 1,
            "msg": HIG "✨ 一道清靈符光籠罩了 $target，滌盪凡塵濁氣並撫平經脈創傷。\n" NOR,
            "apply_func": "skill_dao_fudun"
        ]),

        // ══════════════════════════════════════════════════════════
        // ── 【物】道途 (萬物為用：竭精力 sp，依賴 dex / per) ──
        // ══════════════════════════════════════════════════════════
        "gong_qiaojin": ([
            "name": "百工巧勁",
            "type": "physical",
            "path": "wu",
            "path_name": "【物】道",
            "cost_pool": "sp",
            "cost": 15,
            "level": 10,
            "msg": YEL "🔧 你目光如尺鎖定關節支點，使出『$name』順勢借力打力，精準卸開並反創 $target！\n" NOR,
            "apply_func": "skill_gong_qiaojin"
        ]),
        "gong_yingli": ([
            "name": "應力破點",
            "type": "physical",
            "path": "wu",
            "path_name": "【物】道",
            "cost_pool": "sp",
            "cost": 25,
            "level": 31,
            "msg": HIY "📐 你洞悉 $target 發力結構之脆弱節點，一記『$name』直擊應力交匯處，瞬間瓦解其防禦！\n" NOR,
            "apply_func": "skill_gong_yingli"
        ]),
        "gong_fengdu": ([
            "name": "雄黃封毒散",
            "type": "physical",
            "path": "wu",
            "path_name": "【物】道",
            "cost_pool": "sp",
            "cost": 20,
            "level": 31,
            "msg": GRN "🧪 你袖中機簧輕響，揚手灑出『$name』，辛烈藥霧順著呼吸侵蝕 $target 的氣血與精力！\n" NOR,
            "apply_func": "skill_gong_fengdu"
        ]),
        "gong_jiguan": ([
            "name": "地弩穿心機",
            "type": "physical",
            "path": "wu",
            "path_name": "【物】道",
            "cost_pool": "sp",
            "cost": 30,
            "level": 31,
            "msg": WHT "⚙️ 你手腕急抖扣動連環機括，『$name』三枚精鋼破甲錐呈品字形直射 $target 要害！\n" NOR,
            "apply_func": "skill_gong_jiguan"
        ]),
        "gong_xingzhen": ([
            "name": "辨症行針",
            "type": "support",
            "path": "wu",
            "path_name": "【物】道",
            "cost_pool": "sp",
            "cost": 15,
            "level": 1,
            "msg": HIG "🪡 你撚動三寸毫針刺入 $target 經絡大穴，疏通鬱結氣血並提振生機。\n" NOR,
            "apply_func": "skill_gong_xingzhen"
        ])
    ]);
}

// ── 三角生剋倍率計算（力剋法、法剋物、物剋力） ──────────────────
// 回傳百分比倍率：克制 125%，被克 85%，同道或無道途 100%
int calc_triangular_modifier(string atk_path, string def_path) {
    if (!atk_path || !def_path || atk_path == "" || def_path == "" || atk_path == def_path) {
        return 100;
    }
    if (atk_path == "li" && def_path == "fa") return 125;
    if (atk_path == "fa" && def_path == "wu") return 125;
    if (atk_path == "wu" && def_path == "li") return 125;

    if (atk_path == "fa" && def_path == "li") return 85;
    if (atk_path == "wu" && def_path == "fa") return 85;
    if (atk_path == "li" && def_path == "wu") return 85;
    return 100;
}

// 內部輔助：套用三角生剋與內城法網修正
int apply_combat_modifiers(object me, object target, string atk_path, int base_dmg) {
    int dmg = base_dmg;
    string def_path = target ? target->query_path() : "";
    int tri_mod = calc_triangular_modifier(atk_path, def_path);
    if (tri_mod > 100) {
        write(HIY "【三元生剋】你的道途之力正中對方破綻，招式威力提升！\n" NOR);
    }
    dmg = dmg * tri_mod / 100;

    // 內城絕靈法網檢核：法道招式在法網覆蓋區若無受牒度牒 (lic_diviner)，將遭法網鎮壓反噬
    if (atk_path == "fa" && me && environment(me)) {
        object city_d = load_object(CITY_D);
        string room_file = base_name(environment(me));
        if (strsrch(room_file, ".c") == -1) room_file += ".c";
        if (city_d && city_d->is_spirit_sealed_grid(room_file)) {
            if (me->query_qualification("lic_diviner") <= 0) {
                write(HIR "【絕靈法網反噬】你未持宣道司受牒度牒，在內城強行引動靈機遭法網鎮壓，神識受創且法術威力折損過半！\n" NOR);
                me->receive_sen_damage(10);
                dmg = dmg / 2;
            }
        }
    }

    if (dmg < 1) dmg = 1;
    return dmg;
}

// ── 【力】道途招式實作 ──────────────────────────────────────

int skill_wu_fuhu(object me, object target) {
    int base = me->query_attack() * 150 / 100 + me->query_stat("str") * 2 + random(15);
    int dmg = apply_combat_modifiers(me, target, "li", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_wu_kaishan(object me, object target) {
    int hit1 = apply_combat_modifiers(me, target, "li", me->query_attack() + me->query_stat("str") * 2 + random(10));
    int hit2 = apply_combat_modifiers(me, target, "li", me->query_attack() + me->query_stat("con") * 2 + random(10));
    target->receive_damage(hit1);
    target->receive_damage(hit2);
    return hit1 + hit2;
}

int skill_wu_qixue(object me, object target) {
    int base = (me->query_stat("str") + me->query_stat("con")) * 3 + random(20);
    int dmg = apply_combat_modifiers(me, target, "li", base);
    int sen_burn = me->query_stat("con") * 2;
    target->receive_damage(dmg);
    target->receive_sen_damage(sen_burn);
    return dmg;
}

int skill_wu_gong_sheshi(object me, object target) {
    int base = me->query_attack() * 180 / 100 + me->query_stat("str") * 2 + random(20);
    int dmg = apply_combat_modifiers(me, target, "li", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_wu_pijia(object me, object target) {
    int heal = me->query_stat("con") * 5 + random(20);
    target->heal_kee(heal);
    return heal;
}

// ── 【法】道途招式實作 ──────────────────────────────────────

int skill_dao_jiefa(object me, object target) {
    int base = (me->query_stat("int") + me->query_stat("spi")) * 3 + random(20);
    int dmg = apply_combat_modifiers(me, target, "fa", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_dao_fuzhen(object me, object target) {
    int base = me->query_stat("spi") * 5 + me->query_stat("int") * 2 + random(25);
    int dmg = apply_combat_modifiers(me, target, "fa", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_dao_jinglei(object me, object target) {
    int base = (me->query_stat("int") + me->query_stat("spi")) * 4 + random(30);
    int dmg = apply_combat_modifiers(me, target, "fa", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_dao_fudun(object me, object target) {
    int heal = me->query_stat("spi") * 5 + random(20);
    target->heal_kee(heal);
    target->heal_sen(me->query_stat("int") * 2);
    object city_d = load_object(CITY_D);
    if (city_d) city_d->cleanse_turbidity(target, 15);
    return heal;
}

// ── 【物】道途招式實作 ──────────────────────────────────────

int skill_gong_qiaojin(object me, object target) {
    int base = me->query_attack() + (me->query_stat("dex") + me->query_stat("per")) * 2 + random(15);
    int dmg = apply_combat_modifiers(me, target, "wu", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_gong_yingli(object me, object target) {
    int base = me->query_attack() * 140 / 100 + me->query_stat("per") * 4 + random(20);
    int dmg = apply_combat_modifiers(me, target, "wu", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_gong_fengdu(object me, object target) {
    int base = (me->query_stat("dex") + me->query_stat("per")) * 3 + random(15);
    int dmg = apply_combat_modifiers(me, target, "wu", base);
    int sp_drain = me->query_stat("per") * 2;
    target->receive_damage(dmg);
    target->receive_sp_damage(sp_drain);
    return dmg;
}

int skill_gong_jiguan(object me, object target) {
    int base = (me->query_stat("dex") + me->query_stat("per")) * 4 + random(25);
    int dmg = apply_combat_modifiers(me, target, "wu", base);
    target->receive_damage(dmg);
    return dmg;
}

int skill_gong_xingzhen(object me, object target) {
    int heal = me->query_stat("per") * 5 + random(20);
    target->heal_kee(heal);
    target->heal_sp(me->query_stat("dex") * 2);
    return heal;
}

mapping query_recipe(string id) { return skills[id]; }

int do_perform(object me, string sid, string target_arg) {
    object sk_d = load_object(SKILL_D);
    if (sk_d && !skills[sid]) {
        sid = sk_d->resolve_skill_id(sid);
    }

    mapping s = skills[sid];
    if (!s) {
        write("沒有這種特殊招式。\n");
        return 0;
    }

    // 1. 檢查三元道途限制 (li / fa / wu)
    string my_path = me->query_path();
    if (my_path != s["path"] && me->query_role() != "god") {
        write("這門『" + s["name"] + "』屬於" + s["path_name"] + "法門，與你所修道途不合，無法強行施展。\n");
        return 0;
    }

    // 2. 檢查技能等級
    if (me->query_skill(sid) < s["level"] && me->query_role() != "god") {
        write("你的『" + s["name"] + "』造詣不足（需達等級 " + s["level"] + "），無法發揮這招的威力。\n");
        return 0;
    }

    // 3. 檢查三柱資源 (kee / sen / sp)
    string pool = s["cost_pool"];
    int cost = s["cost"];
    if (pool == "kee") {
        if (me->query_kee() <= cost) {
            write("你的氣血(kee)不足以催動『" + s["name"] + "』（需要至少保留 1 點氣血並消耗 " + cost + " 點氣血）。\n");
            return 0;
        }
    } else if (pool == "sen") {
        if (me->query_sen() < cost) {
            write("你的神識(sen)不足（需要 " + cost + " 點神識）。\n");
            return 0;
        }
    } else if (pool == "sp") {
        if (me->query_sp() < cost) {
            write("你的精力(sp)不足（需要 " + cost + " 點精力）。\n");
            return 0;
        }
    }

    // 4. 尋找目標
    object target;
    if (!target_arg || target_arg == "") {
        target = me->query_combat_target();
    } else {
        target = present(target_arg, environment(me));
    }

    if (!target && s["type"] != "support") {
        write("你要對誰發動招式？\n");
        return 0;
    }

    // 輔助招式預設目標為自身
    if (s["type"] == "support" && !target) target = me;

    if (target && !living(target)) {
        write("你只能對活物施展招式。\n");
        return 0;
    }

    // 5. 扣除對應三柱資源
    if (pool == "kee") me->use_kee(cost);
    else if (pool == "sen") me->use_sen(cost);
    else if (pool == "sp") me->use_sp(cost);

    // 6. 輸出招式訊息
    string msg = s["msg"];
    msg = replace_string(msg, "$target", target->query_name());
    msg = replace_string(msg, "$name", s["name"]);
    write(msg);
    say(me->query_name() + " 施展了『" + s["name"] + "』！\n");

    // 7. 執行招式效果
    call_other(this_object(), s["apply_func"], me, target);

    // 8. 進入戰鬥狀態或處理擊殺
    if (s["type"] == "physical" || s["type"] == "magic") {
        if (target != me) {
            if (target->query_kee() <= 0) {
                write("你擊敗了 " + target->query_name() + "！\n");
                target->die();
                me->stop_combat();
            } else {
                me->attacked_by(target);
                target->attacked_by(me);
            }
        }
    }

    me->save();
    return 1;
}

mapping query_all_skills() { return skills; }
