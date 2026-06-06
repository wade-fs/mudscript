inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔宮");
	set( "build", 19 );
set("long",@LONG
這邊就是天下武林學習魔功之人夢寐以求的魔宮了，雖然空氣中
飄蕩著陣陣妖氣，但並不如何渾濁，只不過偶爾拂過幾許寒風和焚風。

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "out"   : "/open/mogi/forest/room55",
        "north" : __DIR__"room2",
      ]));
        setup();
}
