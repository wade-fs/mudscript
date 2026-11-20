// /d/yunjin/ghost_market.c
// 雲津仙集・雲海鬼市 (Ch.98：岩石裂縫磷火暗集與鬼見愁分級情報交易)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・雲海鬼市");
    set_long("藏於雲津峽谷岩石裂縫底下的無燈暗市，石壁縫隙間插著兩排散發陰森寒光的幽綠磷火蠟燭。\n"
             "十來個戴面具或斗篷的攤主靜立寒風中低聲議價。鬼市最深處那張破竹席後面，坐著從金石府\n"
             "地下黑市挪上雲津的神秘牙商鬼見愁，只認靈石與暗號、不替誰保證據鏈。\n"
             "向上循暗門回到【山道車馬行】，向東北狹縫可繞至【鬼市暗巷與萬寶閣後門交界】。\n");

    set_exits(([
        "up":        "/d/yunjin/mountain_caravan_yard.c",
        "northeast": "/d/yunjin/wanbao_back_alley.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/under_black_market_broker.c");
}
