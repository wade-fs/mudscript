// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","魔界村外");
        set ("long","這裡是已經靠近妖魔古城了，在這近距離的情況下，你發現這棟古
堡相當龐大，上空不斷閃著魔電，外表陰陰藍藍的，亂詭異的。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east"  : __DIR__"b",
            "south"  : __DIR__"d",
      ]));

       

        setup();
}
