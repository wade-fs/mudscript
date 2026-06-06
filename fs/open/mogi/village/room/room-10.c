//room:/u/e/eva/village/room/room-10.c    made by eva
#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create ()
{
  set ("short", "魔界村西村口");
  set ("long", @LONG

    這裡是魔界村的西村口, 魔界村位於魔界的正中央, 由於在村中
自古以來, 有高人在此設下了五行之陣, 憑藉著五行相生相剋的力量
, 巧妙的運用使魔物無法進入, 使這裡變成魔界中唯一的樂土, 僅有
人類以及低等魔物可以進入.

LONG);

  set("no_magic", 1);
  set("outdoors", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
"west" : "/open/mogi/dragon/dr1",
  "east" : __DIR__"room-11",
]));
  set("no_fight", 1);
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

 int valid_leave(object me,string dir)
{
    if ( me==this_player() && dir=="west" )
        {
        tell_object(me,HIM"你輕輕巧巧的穿過力場, 出了魔界村!\n"NOR);
        }
    return ::valid_leave(me,dir);
} 
