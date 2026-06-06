// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "天璇樓");
  set ("long", @LONG
這是七星塔中的第六層樓, 到達這裡, 你一股倦意突然起來,
令你有心於而力不足的感覺, 心中有一絲絲想放棄的感覺, 突然
一陣笑聲, 原來是樓主的笑聲, 由於他剛領悟到更一層的武學,
看到你來到此地, 馬上跑到你的身邊, 邀你切磋。
LONG);

  set("exits", ([ /* sizeof() == 2 */
     "up" : "/open/mogi/forest/entrance",
  "out" : __DIR__"room12.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star3.c" : 1,
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
