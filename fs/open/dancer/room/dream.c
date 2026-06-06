// Room: /open/dancer/room/dream.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIY + "幽雅的莊院" + NOR);
  set ("long", @LONG
在你的面前是一座幽雅的莊院，而四周則種滿了鮮花傳來陣陣花
香，看來此處就是傳說中的夜夢小築了。門口還有兩位美麗的少女在
看守著。你的心情不由興奮起來，心想快能見到月牙兒了。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/dancer/room/r12-2.c",
  "enter" : "/open/dancer/room/rooms5.c",
]));
   set("objects", ([ /* sizeof() == 1 */
   "/open/dancer/npc/rgirl.c" : 2,
  ]));

  set("light_up", 1);

  setup();
}
 int valid_leave(object me, string dir)
{
if( dir=="enter" )
   if( me->query("gender")!="女性" && !me->query("quests/moon"))
   return notify_fail("只有女人才能進夜夢小築喔!\n");
return ::valid_leave(me,dir);
 }
