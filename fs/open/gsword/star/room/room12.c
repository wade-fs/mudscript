// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "天璇樓門口");
  set ("long", @LONG
你經過走道, 終於來到了這, 你已發覺到眼前有一道門 
在門的上面有一塊扁額, 上面寫著天璇樓, 此時樓外有兩個
守衛攔住你的去路, 令你心中忿恨不已, 想痛扁守衛一番。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room11.c",
  "enter" : __DIR__"star6.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/swordsman.c" : 2,
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="enter" && present("swordsman",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以為你能活得過去嗎??"
+RANK_D->query_respect(me)+"你去死吧!\n");
return ::valid_leave(me,dir);
}
