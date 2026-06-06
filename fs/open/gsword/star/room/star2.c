// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "玉衡樓");
	set( "build", 13 );
  set ("long", @LONG
你已經到達第二層, 而塔中的亮度已經影響不到你了, 
往周圍一望, 才發覺到這裡的擺設十分的漂亮, 擺置著許許
多多的武器, 以及許多的花瓶及擺飾, 而樓主正站在向上的
樓梯口前, 靜靜的執行自己的職務, 但眼中仍有著一股漠落
的表情, 可能由於長年只能呆在這吧。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room5.c",
  "out" : __DIR__"room4.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star6.c" : 1,
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
