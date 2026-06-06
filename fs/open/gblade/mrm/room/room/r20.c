// Room: /u/m/moner/room/room/room/r13.c 
inherit ROOM;
 
void create ()
{
set("short","魔龍塔");
  set ("long", @LONG

這裡是魔龍塔的第六層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。

LONG);
set("objects",([
"/daemon/class/blademan/npc/sbman7.c":1,
]));
  set("exits", ([ /* sizeof() == 2 */
"climb":"/open/gblade/mrm/room/class/r1.c",
  "south" : __DIR__"r19.c",
]));
set("no_plan",1);
//add no transmit by bss
  set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir)
{
if(dir=="climb")
if(present("prayer man",environment(me)))
return notify_fail("你無法往上走！\n");
if(!userp(me))
return notify_fail("只有玩者才能進!!!!\n");
return ::valid_leave(me,dir);
}
