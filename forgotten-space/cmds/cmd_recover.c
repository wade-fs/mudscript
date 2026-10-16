// mudlib/cmds/cmd_recover.c
// 隨地調息與吐納指令：rest / 休息 / 調息 / breathe / tuna / 吐納 / 凝神

#include "/include/ansi.h"
#include "/include/globals.h"
inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->is_fighting()) {
        write(HIR "你正在生死搏殺之中，哪有暇心分神調息吐納！\n" NOR);
        return 1;
    }

    if (verb == "rest" || verb == "休息" || verb == "調息") {
        if (me->query(VITAL_KEE) >= me->query("max_kee") && me->query(VITAL_SP) >= me->query("max_sp")) {
            write(CYN "你目前氣血充盈、精力飽滿，無需停步休息。\n" NOR);
            return 1;
        }
        int rec_kee = 12 + me->query_stat("con") / 2;
        int rec_sp  = 18 + me->query_stat("dex") / 2;
        me->add(VITAL_KEE, rec_kee);
        me->add(VITAL_SP, rec_sp);

        write(CYN "你尋了一處僻靜角落稍作歇息，放鬆緊繃的筋骨，緩緩平復急促的呼吸...\n" NOR);
        write(sprintf(HIG "【調息休整】你的體力漸漸回湧（氣血 +%d，精力 +%d）。\n" NOR, rec_kee, rec_sp));
    } else {
        if (me->query(VITAL_SEN) >= me->query("max_sen") && me->query(VITAL_SP) >= me->query("max_sp")) {
            write(HIC "你目前靈台清明、神完氣足，無需刻意凝神吐納。\n" NOR);
            return 1;
        }
        int rec_sen = 15 + me->query_stat("spi") / 2;
        int rec_sp  = 12 + me->query_stat("per") / 2;
        me->add(VITAL_SEN, rec_sen);
        me->add(VITAL_SP, rec_sp);

        write(HIC "你微闔雙目，舌抵上顎，依循呼吸節律徐徐吐故納新，收斂發散的心神...\n" NOR);
        write(sprintf(HIG "【吐納凝神】你的心神漸歸澄澈（神識 +%d，精力 +%d）。\n" NOR, rec_sen, rec_sp));
    }

    object cmd_info = load_object("/cmds/cmd_info");
    if (cmd_info) {
        cmd_info->main(me, "", "");
    }
    return 1;
}

string *query_verbs() {
    return ({ "rest", "休息", "調息", "breathe", "tuna", "吐納", "凝神" });
}

string query_category() {
    return select_lang(([ "en": "Action", "zh-TW": "行動", "zh-CN": "行动" ]));
}

string help() {
    return select_lang(([
        "en": "【Recovery Commands】\n  rest / 休息 / 調息     Rest to recover Kee (HP) and Stamina (SP).\n  breathe / tuna / 吐納  Breathe and meditate to recover Sen (MP) and Stamina (SP).\n",
        "zh-TW": "【調息恢復指令】\n  rest / 休息 / 調息     原地稍作歇息，中速恢復「氣血 (kee)」與「精力 (sp)」。\n  breathe / tuna / 吐納  收斂心神吐故納新，中速恢復「神識 (sen)」與「精力 (sp)」。\n  （提示：在鐵匠鋪飲水、茶棚喝茶、草廬聞藥、道觀打坐或溪邊掬水可獲得更高速的場景恢復）\n",
        "zh-CN": "【调息恢复指令】\n  rest / 休息 / 调息     原地稍作歇息，中速恢复「气血 (kee)」与「精力 (sp)」。\n  breathe / tuna / 吐纳  收敛心神吐故纳新，中速恢复「神识 (sen)」与「精力 (sp)」。\n"
    ]));
}
