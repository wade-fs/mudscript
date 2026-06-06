// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "開陽樓");
	set( "build", 13 );
  set ("long", @LONG
你已經身在七星塔中的第三層了, 對於強烈的光線已不在對
你產生影響了, 在牆邊, 你看到了一個火爐, 有位劍士正揮汗如
雨正在打造著兵器, 原來七星塔中所有劍士的劍, 都是由他一人
所打造的, 當他一望到你, 馬上拿起放在一旁的劍, 鎮守到樓梯
口的地方, 不讓你擅入．
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room7.c",
  "out" : __DIR__"room6.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star5.c" : 1,
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
