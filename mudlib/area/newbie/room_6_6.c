#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short("古老遺跡入口");
    set_long("這裡是一處古代建築的遺跡，殘缺的石牆仍然聳立，牆面上雕刻著難以辨認的浮雕。地面的裂縫中長滿了藤蔓，偶爾能聽見地底傳來的低鳴聲。\n");
    set_coordinate(6, 6, 0);
    add_exit("east",  "/area/newbie/room_7_6.c");
    add_exit("west",  "/area/newbie/room_5_6.c");
    add_exit("south", "/area/newbie/room_6_5.c");

    // 遺跡入口有土蚯蚓出沒
    object worm = clone_object("/npc/creature/earth_worm.c");
    if (worm) move_object(worm, this_object());
}
