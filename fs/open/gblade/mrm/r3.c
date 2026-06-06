// Room: /u/m/moner/room/r2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "魔龍塔");
  set ("long", @LONG

這裡是魔龍塔的外圍，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。
你仔細一看，左邊石塊上似乎有字(paper)。

LONG);
set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r2.c",
  "enter" : __DIR__"r4.c",
]));
set("item_desc",([
"paper":"魔龍塔迷宮，是以四季的運行所設制而成，不懂四季運行的\n"+
        "必招致危險。\n"+
        "                                            神秘人留\n",
]));
set("objects",([
"/daemon/class/blademan/npc/corpse.c":2,
]));
  setup();
  replace_program(ROOM);
}
