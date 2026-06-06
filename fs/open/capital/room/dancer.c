//room:/open/dancer/room/start.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIY "舞者公會" NOR );
  set ("long", @LONG

                舞者公會

這裡是舞者的公會你可以在這裡加入(join)成為舞者
甚至可以直接拜公會的主管為師！但是令人感到不解
的是為何遠在鏡月島的夜夢小築其公會會設在天子腳
下的京城呢？

LONG);

  set("light_up", 1);
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 1 */
 "west" : __DIR__"r69",

]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/master_linr.c" : 1,
]));

  setup();
  call_other("/obj/dancer_bc.c","???");
  }
