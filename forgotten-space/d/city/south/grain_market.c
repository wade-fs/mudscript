// d/city/south/grain_market.c
// 官辦糧食市集 (直連青河縣產區)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城南水陸・官辦糧食市集");
    set_long("這座露天大集市內擺滿了排排竹席與斗秤，散發著穀麥與油料的純樸氣息。\n"
             "自青河縣水運抵達的優質稻米、大麥、菜籽油多在此批發集散。\n"
             "糧行會首與米商坐莊正在看樣定價，全城飯館客棧與軍營皆在此採購主糧。\n"
             "東面通往大料初堆棧，往西穿過水門石拱直達西水門漕運碼頭，\n"
             "向南是一座戒備嚴密的大糧倉。\n");

    set_exits(([
        "east":  "/d/city/south/yard_material.c",
        "west":  "/d/city/south/canal.c",
        "south": "/d/city/south/warehouse_grain.c",
    ]));

    set("is_outdoor", 1);
    set("has_shop", 1);
    spawn_npc("/clone/npc/south_grain_guildhead.c");
}
