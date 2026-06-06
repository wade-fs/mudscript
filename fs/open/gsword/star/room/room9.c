// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走道");
	set( "build", 13 );
  set ("long", @LONG
你剛剛邁入七星塔第五層, 在此處你看到了滿地的枯骨, 
四周毫無光線, 伸手不見五指, 遠遠的望去, 只看到一點亮光
, 令你想立刻飛奔過去, 只見一陣陣的陰風撲面而來, 此時才
發覺有許多鬼影向你這奔來．
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room10.c",
  "down" : __DIR__"star4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/corpse.c" : 4,
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="north" && present("corpse",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以為你能活得過去嗎??"
+RANK_D->query_respect(me)+"你去死吧!\n");
return ::valid_leave(me,dir);
}
