inherit ROOM;

void create ()
{
  set ("short", "魔教分壇");
  set ("long", @LONG
牆上架著一具具雄雄的火把，中間則供奉著一座非人非蛇的魔神
圖騰，這種和平南城格格不入的奇怪裝飾，便是冥蠱魔教處於平南城
的根據地了。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/ping/room/road1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/elder3.c" : 1,
]));

  setup();
}
