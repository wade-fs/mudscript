// d/village/forge.c
// 黑石鋪・老鐵匠鋪・打鐵爐房 (打鐵學徒出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("老鐵匠鋪・打鐵爐房");
    set_long("這是一間坐落於街市東側的粗獷打鐵工坊。粗大的巨木樑柱被炭煙熏得烏黑，\n"
             "屋角一人高的巨大牛皮風箱伴隨著拉動發出沉悶的呼哧喘息。中央炭火爐中\n"
             "赤炎翻滾，滾燙的熱浪撲面而來。地上散落著幾塊沉重的鐵砧、碎礦石與盛\n"
             "滿黑褐色淬火水的石槽。你從小在火星四濺與叮噹鐵鳴中長大，隨身那柄打\n"
             "鐵舊鐵錘已被握得溫熱錚亮。\n");

    set_exits(([
        "west": "/d/village/square.c",
    ]));

    set("is_outdoor", 0);
    set("has_forge", 1);

    spawn_npc("/clone/npc/tie_smith.c");
}
