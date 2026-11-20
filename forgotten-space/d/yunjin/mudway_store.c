// /d/yunjin/mudway_store.c
// 雲津仙集・泥途商棧 (Ch.84, Ch.85, Ch.90：五子自由樞紐與朔望暗網)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・泥途商棧");
    set_long("一間由舊鞍具煤倉改建而成的簡樸石砌商棧，屋頂瓦片補得嚴密，前後門皆換上了\n"
             "林鐵生親手打製的精鋼雙契暗鎖。牆角碼著數十垛烈礬無煙耐火炭與青河苦參乾貨，\n"
             "榆木帳桌旁擺著一冊記錄嚴謹的雙聯交割帳簿與「朔望貨單」暗網分類夾。\n"
             "向東出門回到【西街貨棧區】。\n");

    set_exits(([
        "east": "/d/yunjin/western_warehouse_street.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/qiu_he.c");
}
