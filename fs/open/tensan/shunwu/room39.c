inherit ROOM;
#include <ansi.h>
#include "room.msg"

void create () {
        set ("short","玄武幻陣");
        set ("long",
        (: print_room_msg :)
        );
    
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "北門" : __DIR__"room40",
        "南門" : __DIR__"room42",
        "東門" : __DIR__"room41",
        "西門" : __DIR__"room36",
        ]));

        setup();
}
