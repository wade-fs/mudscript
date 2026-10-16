// clone/npc/tie_smith.c
// 老鐵匠 阿鐵 - 老鐵匠鋪的沉穩師傅

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("阿鐵");
    set_short(YEL "老鐵匠" NOR " 阿鐵");
    set_long("一位鐵塔般粗壯沉穩的中年漢子，赤裸著精鋼般的厚實臂膀，古銅色的肌膚上\n"
             "佈滿了燙傷與火星灼痕。他手握一把沉重的八角大鐵錘，每落下一錘，鐵砧上\n"
             "的胚料便濺出漫天耀眼火星。他的眼神深邃堅毅，是黑石鋪百工手藝的頂樑柱。\n");
    set_id(({ "tie", "blacksmith", "smith", "atie", "阿鐵", "老鐵匠", "鐵匠" }));

    set_level(25);
    set_stat("str", 30);
    set_stat("con", 28);
    set_stat("dex", 18);
    recalc_stats();

    set_skill_to_teach("crazy_forge", 10);
    set_skill_to_teach("forging", 20);

    add_response(({ "心法", "功法", "瘋魔打鐵法", "調息", "呼吸", "crazy_forge" }),
        "打鐵不只是使蠻力，呼吸若跟不上風箱與鐵錘的節奏，不出三年五臟俱裂！" +
        "老子傳你一套『瘋魔打鐵法(初級)』(learn crazy_forge from tie)，以胸膛為風箱、以意念為鐵錘！");

    add_response(({ "打鐵", "鍛造", "forge", "smith" }), 
        "學打鐵，先學耐得住炭火燒、扛得住鐵錘震！臂力不夠，連粗礦都敲不碎；感知不準，火候差一厘就是一爐廢鐵！");

    add_response(({ "粗礦", "礦石", "ore", "北崖" }), 
        "北崖礦坑送下來的粗鐵礦質地厚重沉凝，是百工鍛造的上佳底子。只可惜洞裡地煞不穩，" +
        "動輒崩落塌方，你若有空，去北崖多起幾塊礦石回來！");

    add_response(({ "身世", "學徒", "鐵錘", "background" }), 
        "你從小在炭火與鐵砧聲中長大，手裡那把舊鐵錘就是當年在廢鐵堆裡揀出來的。" +
        "好好淬鍊臂力，這天地間唯有手造之物最踏實，莫去學那些整天妄想長生道化的瘋子！");

    add_response(({ "商隊", "金石城", "兵器" }), 
        "金石商會每次來，都要從老子這提走三十把開山柴刀。若是山口商道被雨水沖塌了，" +
        "大夥的生計都要受牽連。");

    add_response(({ "不融黑鐵", "黑鐵", "工聖", "gear" }), 
        "傳說太古大清洗之前，物宗工聖曾鑄造過一種萬火不融的黑鐵構件，上面銘刻微型齒輪與榫卯。" +
        "若是能在粗礦胚料中敲出那等神物，便是百工造物之理未絕！");
}

int accept_object(object who, object ob) {
    if (!who || !ob) return 0;

    if (ob->id("black iron") || ob->query("relic_type") == "wu_gear") {
        tell_object(who, HIY "阿鐵雙手劇烈顫抖著捧起那截黑色金屬，眼中爆發出前所未有的狂熱震撼：\n" +
                         "「這……這是太古不融黑鐵？！上古工聖的傳說竟然是真的！\n" +
                         "這上面的齒輪微度公差，連老子見過最巧的府城大師傅都造不出來！\n" +
                         "好小子，百工造物之理未絕！這東西你且好生收著，萬莫讓外頭商會的吸血鬼看見！」\n" NOR);
        tell_object(who, HIG "阿鐵慎重地將太古不融黑鐵交還到你手中。\n" NOR);
        who->add("exp", 50);
        return 1;
    }

    if (ob->id("ore chunk") || ob->query("is_ore")) {
        tell_object(who, HIG "阿鐵接過粗鐵礦核掂了掂，又塞回你手裡讚道：「好沉凝的北崖老鐵胎！去鐵砧上拉風箱、掄鐵錘鍛打出來 (strike)！」\n" NOR);
        return 1;
    }

    return 0;
}

int do_chat(object me, string topic) {
    if (!topic || topic == "") return 0;
    object ws = load_object(WORLD_STATE_D);

    if (topic == "商隊" || topic == "金石城" || topic == "兵器" || topic == "caravan") {
        if (ws) {
            if (ws->is_caravan_arrived()) {
                tell_object(me, query_name() + " 擦了把熱汗笑道：「金石商會的掌櫃已經在廣場支攤收購了，老子打好的開山柴刀總算能換成現銀了！」\n");
            } else {
                tell_object(me, query_name() + " 沉聲道：「金石商會每次來，都要從老子這提走三十把開山柴刀。若是山口商道斷了，大夥的生計都要受牽連。" + ws->query_garrison_narrative(1) + "」\n");
            }
            return 1;
        }
    }

    if (topic == "礦坑" || topic == "塌方" || topic == "北崖") {
        if (ws) {
            if (ws->is_mine_collapsed()) {
                tell_object(me, query_name() + " 焦急道：「北崖礦坑塌方了！爐子快要斷料，得趕緊去北崖搬開落石！」\n");
            } else {
                tell_object(me, query_name() + sprintf(" 說道：「北崖礦脈目前穩定度在 %d%%，魯老頭他們還在坑裡起礦。」\n", ws->query_mine_stability()));
            }
            return 1;
        }
    }

    if (topic == "任務" || topic == "生計" || topic == "job" || topic == "career" || topic == "物修") {
        object career = load_object(CAREER_D);
        int st = career ? career->query_chain_stage(me, "wu") : 1;
        if (st == 1) {
            tell_object(me, query_name() + " 沉聲道：「金石商隊催得急，但鋪子裡粗礦告罄。北崖礦洞地煞鬆動，老礦工魯大山還在坑裡，你速去北崖接應他 (ask lu about 任務)！」\n");
            return 1;
        } else if (st == 2) {
            tell_object(me, query_name() + " 催促道：「聽說魯老頭被毒瘴嗆著了？快去南谷藥廬找葛半仙求藥！」\n");
            return 1;
        } else if (st == 3) {
            tell_object(me, query_name() + " 點頭道：「藥配好了？快把藥散送去給魯老頭，再把好礦帶回爐房！」\n");
            return 1;
        } else if (st == 4) {
            tell_object(me, query_name() + " 笑道：「料子備齊了！手握鐵錘，拉動風箱，在鐵砧上狠狠鍛打粗礦 (strike ore)，打出一柄像樣的開山柴刀！」\n");
            return 1;
        }
    }

    return ::do_chat(me, topic);
}
