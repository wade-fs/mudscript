// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","一樓底部");
        set ("long","四周都是陰森森的鬼氣,使人越走越覺得心慌。不過你似乎
看到另一端有微弱的燈光。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" : __DIR__"room19",
            "southeast"  : __DIR__"room6",
      ]));

       

        setup();
}
