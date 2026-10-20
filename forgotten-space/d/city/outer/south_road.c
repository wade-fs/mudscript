// d/city/outer/south_road.c
// 金石府外・南嶺官道匯流口 (東線盤木林海官道 450 里與西線重石條石馳道 420 里交匯處)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南嶺官道・雙線匯流口");
    set_long("這是一條自八百里落龍古脈北麓平原向金石府城延伸的官道總匯流口。\n"
             "路旁立著一座高大的指路石闕：往東南延伸的是林木蔥鬱的【南嶺林海官道】(southeast)，\n"
             "經盤木縣與虎跳峽通往黑石鋪（東線全長 450 里，路寬坡緩可通重載大車）；\n"
             "往西南鋪展的則是雙層青石板砌成的【西南條石馳道】(southwest)，經重石縣與\n"
             "落龍西谷棧道通往黑石鋪（西線全長 420 里，西谷懸崖棧道禁行重車）。\n"
             "向北眺望，平原極目處已能看見金石府城巍峨的【金石南關】(north)。\n");

    set_exits(([
        "southeast": "/d/routes/forest_landslide.c",
        "southwest": "/d/routes/stone_highway_pavilion.c",
        "north":     "/d/city/gate/gate_south.c",
    ]));

    set("is_outdoor", 1);
    set_coordinate(0, 10, 0);
}
