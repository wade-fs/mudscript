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
