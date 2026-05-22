#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/room.c";

void create() {
    ::create();
    set_short(HIY("鐵匠鋪"));
    set_long("這是一個熱氣騰騰的作坊，爐火熊熊燃燒。牆上的掛架上展示著各種鋼鐵鑄造的長劍、斧頭與盾牌。地板上散落著一些廢棄的金屬殘渣。\n");
    set_no_combat(1);
    set_has_forge(1);
    set_coordinate(3, 4, 0);
    add_exit("east", "/area/newbie/room_4_4.c");
    add_exit("west", "/area/newbie/room_2_4.c");
    
    // 產生老闆
    spawn_npc("/npc/blacksmith.c");
}
