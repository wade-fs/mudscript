// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "天機樓");
  set ("long", @LONG
這是七星塔中的第五層樓, 剛步入此地, 一陣刺鼻的藥味衝
進了你的鼻子, 令你心中有股噁心的感覺, 你馬上向四周觀望,
發覺四周擺滿了藥材, 而在樓中央放置著丹爐, 原來此樓的樓主
喜歡研究醫術, 當他看你一上來, 馬上惡狠狠的瞪著你, 深怕你
將他煉製的丹藥給偷了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room11.c",
  "out" : __DIR__"room10.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star1.c" : 1,
]));

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
