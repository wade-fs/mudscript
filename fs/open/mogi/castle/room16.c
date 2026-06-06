// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡一樓");
        set ("long","行行復行行,此行的目的你恐怕已忘的一乾二淨了。埋伏的妖怪、險惡的機關
在在都使你想打退堂鼓。東方似乎有一條長廊。

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "east" :  __DIR__"room21",
            "south"  : __DIR__"room15",
            "west"  : __DIR__"room18",
            "northeast"  : __DIR__"room19",
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/mob4" : 2,
      ]));

        setup();
}
