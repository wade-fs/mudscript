// room1.c by roger

inherit ROOM;
#include <ansi.h>
#include "mountain.msg"
void create () {
set ("short","天邪峰");
set ("long","
這裡是天邪峰山腹，前方是片廣大的平原，四周都是光禿禿的峭壁，
看來要上山是非經過這不可了。但是上方似乎有著強烈的妖氣環繞
著，模模糊糊濃霧中似乎夾雜著一道金光，銀光和一道紅光。。。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
       "west" : __DIR__"room19",
       "east" : __DIR__"room16",
      ]));

        set("objects",([ /* sizeof() == 1 */
        __DIR__"npc/gold-ghost" : 1,
        __DIR__"npc/silver-ghost" : 1,
        __DIR__"npc/red-ghost" : 1,
      ]));

        setup();
}
int valid_leave(object me, string dir)

{
if(dir=="west"&&present("ghost",environment(me)))  return 0;

else return 1;
}
