// d/city/center/yamen.c
// 金石都城・府衙正堂

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石府衙・大堂");
    set_long("堂皇威嚴的青磚府衙正堂之上，高懸「明鏡高懸」黑漆金字巨匾。\n"
             "公案後端坐著金石府尹，兩側雁翅排開著按水火棍的威武衙役。\n"
             "周捕頭手按佩刀警惕四顧。此處是全府政務、詞訟斷獄與大案懸賞之核心樞紐。\n"
             "向東南邁出八字大門回到中央青石廣場，\n"
             "向北穿過後廊可通往府衙案卷庫，向東穿過角門則直通金石死牢。\n");

    set_exits(([
        "southeast": "/d/city/center/square.c",
        "north":     "/d/city/center/yamen_archive.c",
        "east":      "/d/city/center/yamen_prison.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    spawn_npc("/clone/npc/yamen_magistrate.c");
    spawn_npc("/clone/npc/yamen_zhou.c");
}
