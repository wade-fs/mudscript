inherit ROOM;

void create ()
{
  set ("short", "青石板路");
	set( "build", 19 );
  set ("long", @LONG

從這裏往北望去，只見崇閣巍峨，層樓高起；面面琳宮合抱，迢迢複道縈
紆；金輝獸面，彩煥璃頭，富麗堂皇。想不到金刀門竟然如此華麗。

LONG);
 
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"g1-9.c",
  "south" : __DIR__"g1-2.c",
  "north" : __DIR__"g1-4.c",
  "east" : __DIR__"g1-10.c",
]));

  setup();
}
