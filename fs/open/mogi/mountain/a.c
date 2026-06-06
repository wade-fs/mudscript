// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","魔界村外");
        set ("long","
這裡是魔界村北村口之外，往北走就可以直達天邪峰了，從這裡可以
看到不遠處積雪的天邪峰了，長年不融。由此可見天邪峰氣溫之低，
光站在這裡就感受了有陣陣的冷意不斷傳來。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north"  : __DIR__"b",
            "south"  : "/open/mogi/village/room/room-01",
      ]));

       

        setup();
}
