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
}
