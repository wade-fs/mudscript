// /d/yunjin/exchange_hall.c
// 雲津仙集・三宗交割廳暨雲海票號 (Ch.84, Ch.90：顧蘭舟核驗實物倉單與準備金)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・三宗交割廳暨雲海票號");
    set_long("堂內不見浮誇的沉香氣，唯有一股淡淡的油墨與冷鐵味道。高大的紅木櫃檯上\n"
             "陳列著三宗物資交割回執木架與信用準備金核驗板，雲海票號女掌櫃顧蘭舟在此專司\n"
             "跨州匯兌、實物倉單抵押保書與延誤違約劃扣清算。\n"
             "向西退回【萬山商埠公所】。\n");

    set_exits(([
        "west": "/d/yunjin/public_office.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/gu_lanzhou.c");
}
