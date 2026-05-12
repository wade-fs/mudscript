#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIW("冒險者公會"));
    set_long("這裡是冒險者們聚集的地方。大廳中央擺放著幾張粗糙的木桌，牆上的布告欄貼滿了各式各樣的委託與懸賞，空氣中瀰漫著麥酒與汗水的氣息。\n");
    set_coordinate(4, 5, 0);
    add_exit("south", "/area/newbie/room_4_4.c");
    add_exit("north", "/area/newbie/room_4_6.c");
    
    // 增加 NPC
    object ob = clone_object("/npc/guild_master.c");
    if (ob) move_object(ob, this_object());
}
