// Room: /open/poison/room/room12
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "說法堂側廳");
  set ("long", @LONG
這裡是說法堂側廳，連同正廳形成一個寬廣舒適的大廳
堂，平常會有許多教眾在此聽法，學習各種武學、知識和技
能。
LONG);
 
 
 
 
 
 
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"r2.c",
  "south" : __DIR__"room11",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/envoy1.c" : 1,
]));

  setup();
}
int valid_leave(object me, string str)
{
if(me->query("class")!="poisoner"&&str=="up")
return notify_fail("非魔教徒不得擅入!!\n");
return ::valid_leave(me,str);
}
