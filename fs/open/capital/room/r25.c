// Room: /open/capital/room/r25.c

inherit ROOM;

void create ()
{
  set ("short", "日落馳道");
	set( "build", 36 );
  set ("long", @LONG
路邊老榕樹蔭下有個挑擔賣酒的，酒很涼，既解渴又過癮，還有開
花蠶豆，椒鹽花生和鹵蛋下酒，口味雖未見佳，做得卻很乾淨。賣酒的
是個白髮蒼蒼的紅鼻子老頭，京城裡一半以上的人都曉得城西有個賣酒
賣了六十年的老頭。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/oldman" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r26",
  "north" : __DIR__"r24",
"west" : "/open/wind-rain/room1",
  "east" : __DIR__"h09.c",
]));
  set("gopath", "north");

  setup();
}
