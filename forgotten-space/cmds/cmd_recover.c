// mudlib/cmds/cmd_recover.c
// 調息與休息指令：
//   - rest / 休息：尚未學習心法前的通用粗淺休息，效果最弱
//   - breathe / tuna / meditate / 吐納 / 凝神 / 調息 / 冥想 / 打坐 / 靜坐：同義詞，運轉已 enable 的初級心法恢復三元並提升心法熟練度

#include "/include/ansi.h"
#include "/include/globals.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->is_fighting()) {
        write(HIR "你正在生死搏殺之中，哪有暇心分神調息休息！\n" NOR);
        return 1;
    }

    // 若當前房間具備特殊打坐/觀想機制 (如 altar.c 孤岩道壇)，優先由環境房間處理
    object env = environment(me);
    if (env && function_exists("do_meditate", env) && (verb == "meditate" || verb == "打坐" || verb == "觀想")) {
        return env->do_meditate(arg);
    }

    object cmd_info = load_object("/cmds/cmd_info");

    // 1. 通用基礎休息 (rest / 休息)：效果最差，不觸發心法
    if (verb == "rest" || verb == "休息") {
        if (me->query(VITAL_KEE) >= me->query("max_kee") && me->query(VITAL_SP) >= me->query("max_sp")) {
            write(CYN "你目前氣血與精力尚算充沛，無需停步乾歇（若已習得心法，可使用 調息/吐納/打坐 運功）。\n" NOR);
            return 1;
        }
        int rec_kee = 6 + me->query_stat("con") / 3;
        int rec_sp  = 8 + me->query_stat("dex") / 3;
        me->add(VITAL_KEE, rec_kee);
        me->add(VITAL_SP, rec_sp);

        write(WHT "你隨地找了個角落蹲坐下來，大口喘氣歇息了片刻（粗淺休息效果有限）。\n" NOR);
        write(sprintf(CYN "【粗淺休息】你的體力略微平復（氣血 +%d，精力 +%d）。\n" NOR, rec_kee, rec_sp));
        if (cmd_info) cmd_info->main(me, "score_quiet", "");
        return 1;
    }

    // 2. 吐納調息同義詞 (breathe / tuna / meditate / 吐納 / 凝神 / 調息 / 冥想 / 打坐 / 靜坐)
    object skill_d = load_object("/secure/skill_d.c");
    string force_sid = me->query("enabled_force");

    if (!force_sid || me->query_skill(force_sid) <= 0) {
        int basic_kee = 5;
        int basic_sen = 6;
        int basic_sp  = 6;
        me->add(VITAL_KEE, basic_kee);
        me->add(VITAL_SEN, basic_sen);
        me->add(VITAL_SP, basic_sp);

        write(YEL "你閉上眼睛胡亂深呼吸了幾口，但因尚未習得或未設定 (enable) 任何調息心法，氣息散亂，收效甚微。\n" NOR);
        write(sprintf(CYN "（氣血 +%d，神識 +%d，精力 +%d。提示：可向出身師長請教獨門初級心法並以 enable 設定）\n" NOR,
            basic_kee, basic_sen, basic_sp));
        if (cmd_info) cmd_info->main(me, "score_quiet", "");
        return 1;
    }

    int lv = me->query_skill(force_sid);
    string sname = skill_d->query_skill_name(force_sid);

    if (force_sid == "dream_sleep") {
        write(HIC "你眼皮微垂，似睡非睡、似醒非醒，依循『" + sname + "』如寒冬老龜蟄伏般綿長呼吸，天地喧囂盡化入夢息...\n" NOR);
    } else if (force_sid == "still_heart") {
        write(HIC "你澄心絕慮，依循『" + sname + "』斬斷紛雜妄念，靈台如古井止水般澄澈，引動周身氣機緩緩歸元...\n" NOR);
    } else if (force_sid == "crazy_forge") {
        write(HIC "你沉腰收腹，胸膛起伏如巨型牛皮風箱鼓盪，依循『" + sname + "』以意為錘，在經絡間反覆鍛打氣血...\n" NOR);
    } else if (force_sid == "herb_breathe") {
        write(HIC "你舌抵上顎，依循『" + sname + "』如深谷青木汲取破曉晨露般徐徐吐濁納清，生機在四肢百骸間流轉...\n" NOR);
    } else if (force_sid == "beast_breath") {
        write(HIC "你收斂周身毛孔氣機，依循『" + sname + "』模擬大荒蟄獸潛伏，呼吸細若游絲卻綿密深長，精神高度凝聚...\n" NOR);
    } else {
        write(HIC "你微闔雙目，運轉『" + sname + "』徐徐吐故納新，收斂發散的心神與氣血...\n" NOR);
    }

    // 五大初級心法功用一致，依心法等級與屬性恢復三元
    int rec_kee = 12 + lv * 2 + me->query_stat("con") / 2;
    int rec_sen = 12 + lv * 2 + me->query_stat("spi") / 2;
    int rec_sp  = 15 + lv * 2 + me->query_stat("per") / 2;

    me->add(VITAL_KEE, rec_kee);
    me->add(VITAL_SEN, rec_sen);
    me->add(VITAL_SP, rec_sp);

    int prof_gain = 8 + me->query_stat("int") / 2;
    me->improve_skill(force_sid, prof_gain);

    int new_lv = me->query_skill(force_sid);
    int cur_exp = me->query_skill_exp(force_sid);
    int req_exp = skill_d->query_upgrade_exp(new_lv);

    write(sprintf(HIG "【運功調息・%s (Lv.%d)】氣血 +%d、神識 +%d、精力 +%d（心法熟練 +%d [%d/%d]）。\n" NOR,
        sname, new_lv, rec_kee, rec_sen, rec_sp, prof_gain, cur_exp, req_exp));

    if (cmd_info) cmd_info->main(me, "score_quiet", "");
    return 1;
}

string *query_verbs() {
    return ({ "rest", "休息", "breathe", "tuna", "meditate", "吐納", "凝神", "調息", "冥想", "打坐", "靜坐" });
}

string query_category() {
    return select_lang(([ "en": "Action", "zh-TW": "行動", "zh-CN": "行动" ]));
}

string help() {
    return select_lang(([
        "en": "【Recovery & Cultivation Commands】\n  rest / 休息                                 Basic rest (weakest recovery, no skill needed).\n  breathe / tuna / meditate / 吐納 / 凝神 / 調息 / 冥想 / 打坐 / 靜坐\n                                              Circulate your enabled inner skill (enable) to recover Kee, Sen, and SP while improving skill proficiency.\n",
        "zh-TW": "【調息與休息指令】\n  rest / 休息\n    還沒學心法前的通用粗淺休息動作，恢復效果最弱。\n  breathe / tuna / meditate / 吐納 / 凝神 / 調息 / 冥想 / 打坐 / 靜坐\n    同義詞，自動運轉已透過 enable 設定的初級心法（如睡夢大法、止心大法、瘋魔打鐵法、百草吐納法、山林龜息法），大幅恢復氣血、神識與精力，並累積心法熟練度。\n",
        "zh-CN": "【调息与休息指令】\n  rest / 休息\n    还没学心法前的通用粗浅休息动作，恢复效果最弱。\n  breathe / tuna / meditate / 吐纳 / 凝神 / 调息 / 冥想 / 打坐 / 静坐\n    同义词，自动运转已透过 enable 设定的初级心法，大幅恢复气血、神识与精力，并累积心法熟练度。\n"
    ]));
}
