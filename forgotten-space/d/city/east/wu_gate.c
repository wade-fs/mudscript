// d/city/east/wu_gate.c
// 鎮武軍鎮外轅門 (力道世俗門戶)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("鎮武軍鎮・外轅門");
    set_long("此處是金石都城東部鎮武軍鎮與八方武館的營防門戶。\n"
             "兩排以生鐵包裹的粗壯鹿砦拒馬斜插於道旁，兩座高聳的瞭望木樓上立著披甲弓弩手。\n"
             "軍營中隱隱傳來成百上千健兒齊聲咆哮的震天操演聲，空氣中熱血澎湃。\n"
             "西出轅門可回到中央青石廣場，東通金石東關城門，\n"
             "向北穿過轅門便進入軍鎮大校場。\n");

    set_exits(([
        "west":  "/d/city/center/square.c",
        "east":  "/d/city/gate/gate_east.c",
        "north": "/d/city/east/wu_plaza.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/city_gate_guard.c");
    spawn_npc("/clone/npc/wu_gate_squadleader.c");
}
