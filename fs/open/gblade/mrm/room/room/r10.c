// Room: /u/m/moner/room/room/room/r1.c 
inherit ROOM;
 
void create ()
{
  set ("short", "魔龍塔");
  set ("long", @LONG

這裡是魔龍塔的第五層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。

LONG);

  set("exits", ([ /* sizeof() == 6 */
  "春" : __DIR__"r9.c",
"夏":__DIR__"r11.c",
  "冬" : __DIR__"r4.c",
  "秋" : __DIR__"r3.c",
]));
set("no_transmit",1);
set("objects",([
"/daemon/class/blademan/npc/corpse5.c":4,
]));
  setup();
  replace_program(ROOM);
}
