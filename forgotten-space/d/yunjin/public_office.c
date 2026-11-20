// /d/yunjin/public_office.c
// 雲津仙集・萬山商埠公所 (Ch.84, Ch.90：羅九秤審驗跨州信印與登記)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・萬山商埠公所");
    set_long("寬敞莊嚴的三層青石大殿。正堂迎面一排紅漆木櫃檯，後方掛著一面巨幅烏木\n"
             "牌價板，明列「一兩金石官銀折兩枚下品靈石票」及「三宗歲貢折額」。\n"
             "掌印羅九秤端坐於「新商號掛牌核驗」櫃後，旁有公所執法書吏登記契約版本與倉損。\n"
             "西北回返【萬山廣場】，東側過廊直通【三宗交割廳暨雲海票號】，南側通往【萬寶閣雲津分號】。\n");

    set_exits(([
        "northwest": "/d/yunjin/wanshan_square.c",
        "east":      "/d/yunjin/exchange_hall.c",
        "south":     "/d/yunjin/wanbao_pavilion.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/luo_jiucheng.c");
}
