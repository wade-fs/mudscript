// d/village/hunter_cabin.c
// 黑石鋪・林邊茅屋・獵戶哨亭 (獵戶之子出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("林邊茅屋・獵戶哨亭");
    set_long("這是一座依著大荒鹿角柵欄搭建的高腳圓木哨亭。粗木牆上散發著松脂與煙燻\n"
             "氣息，樑上懸掛著幾條風乾肉條、幾張抹了防蟲油的灰狼皮與一副粗重獸弓。\n"
             "角落的火塘裡燃著苦艾草與枯松枝，青煙裊裊。推開厚木門，眼前便是遮天\n"
             "蔽日的大荒外緣，遠處不時傳來狼嚎禽鳴。那把伴你防身多年的生鏽厚背柴刀\n"
             "就斜插在門邊木樁上。\n");

    set_exits(([
        "south":     "/d/village/forest.c",
        "west":      "/d/village/square.c",
        "northwest": "/d/village/square.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/zhao_hunter.c");
}
