//open/prayer/room/punch1-1 

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "教主的房間");
  set ("long", @LONG

    你現在所在的位置，正是聖火教主的房間，這是教主與教主夫人休息
的地方，四周傳來陣陣的花香，濃郁的花香使你感覺到，身在御花園一般
，仔細一聞還來陣陣的花香是來自教主夫人的身上...... 

LONG);

  set("exits", ([ /* sizeof() == 1 */
        "out" : "/open/prayer/room/punch1",             //幫主
]));
   set("light_up", 1);

  setup();
}
 
