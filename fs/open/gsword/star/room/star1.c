// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "瑤光樓");
  set ("long", @LONG
這是七星塔中的第一層樓, 塔中充斥無數炫麗的光線, 
令你走到此樓, 瞬間眼睛睜不開來, 過了不久, 眼睛漸漸
的適應了四周的亮度, 只見眼前站著一位威嚴的劍士, 令
你心生畏懼, 讓你有點不敢向前邁去．
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room3.c",
  "out" : __DIR__"room2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star7.c" : 1,
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="up" && present("starman",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以為你能活得過去嗎??"
+RANK_D->query_respect(me)+"你去死吧!\n");
return ::valid_leave(me,dir);
}
