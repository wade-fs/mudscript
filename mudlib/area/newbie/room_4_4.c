#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(CYAN("中央廣場"));
    set_long("這裡是新手村的正中央，寬闊的廣場由潔淨的石板鋪成。廣場中央矗立著一座巨大的噴泉，水花在陽光下閃爍著七彩的光芒。噴泉旁有幾隻野鴿子在踱步，偶爾有哥布林的叫聲從東邊的林子傳來。這裡也是許多冒險者出發與休憩的起點。\n");
    set_no_combat(1);
    set_coordinate(4, 4, 0);
    add_exit("north", "/area/newbie/room_4_5.c");
    add_exit("south", "/area/newbie/room_4_3.c");
    add_exit("west",  "/area/newbie/room_3_4.c");
    add_exit("east",  "/area/newbie/room_5_4.c");

    // 廣場守衛
    spawn_npc("/npc/guard.c");

    // 廣場上的野生風精靈（白天出現，被動）
    object sprite = clone_object("/npc/creature/wind_sprite.c");
    if (sprite) move_object(sprite, this_object());
}
