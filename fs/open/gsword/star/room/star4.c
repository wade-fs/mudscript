// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "天權樓");
  set ("long", @LONG
這是七星塔的第四層, 當你剛走到此樓, 突然有眼睛感到一陣
刺痛, 原來是此處的光線更加的強烈, 令你在此的休息了一會才慢
慢的好轉起來, 此時你立刻望向四周, 而這的設計跟第三層樓一樣
, 只不過周圍擺放著星之裝備, 原來所有七星塔中的裝備, 是從這
生產出來的, 而樓梯口旁站到樓主, 樓主臉上充滿著倦態, 原來他
剛在休息就被你的腳步聲吵醒了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room9.c",
  "out" : __DIR__"room8.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star4.c" : 1,
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
