#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIC("新兵訓練場"));
    set_long("這是一塊平整的空地，地面被踩得很實。四周擺放著一些木質的人偶和練習用的木劍。\n訓練教官正在這裡指導新兵們如何進行基礎的戰鬥。\n");
    set_no_combat(1);
    set_coordinate(1, 1, 0);
    add_exit("east",  "/area/newbie/room_2_1.c");
    add_exit("west",  "/area/newbie/room_0_1.c");
    add_exit("north", "/area/newbie/room_1_2.c");
    add_exit("south", "/area/newbie/room_1_0.c");

    // 產生老闆
    spawn_npc("/npc/trainer.c");
}
