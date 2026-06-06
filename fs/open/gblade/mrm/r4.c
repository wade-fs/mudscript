// Room: /u/m/moner/room/r2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "魔龍塔");
  set ("long", @LONG

這裡是魔龍塔的第一層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。

LONG);
set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"r3.c",
  "east" : __DIR__"r5.c",
]));
set("objects",([
"/daemon/class/blademan/npc/corpse1.c":3,
]));
  setup();
  replace_program(ROOM);
}
