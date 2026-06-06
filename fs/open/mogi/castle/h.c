// by roger
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","魔界村外");
        set ("long","這裡是魔界村的東北方，在這不遠處聳立著妖魔古城。由遠方看來這古
堡相當龐大，上空不斷閃著魔電，外表陰陰藍藍的，亂詭異的。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north"  : __DIR__"f",
            "west"  : "/open/mogi/village/room/room-17",
      ]));

       

        setup();
}
