// d/city/west/dao_observatory.c
// 宣道司・摘星觀象台 (觀星師星淵)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("宣道司・摘星觀象台");
    set_long("這是一處懸於宣道司殿頂之上的露天觀星石台，四方凌空，俯瞰全城。\n"
             "台上架設著多座由百工總會製造的精銅渾天儀與透鏡鏡筒。\n"
             "觀星師星淵日夜在此推演星宿天象、測候靈機氣脈。\n"
             "向下 (down) 順旋梯可回到宣道正堂，沿外牆石級向上 (up) 可爬上偏殿屋頂 (dao_roof)。\n");

    set_exits(([
        "down": "/d/city/west/dao_hall.c",
        "up":   "/d/city/west/dao_roof.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/dao_xingyuan.c");
}
