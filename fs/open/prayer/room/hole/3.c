///open/prayer/room/hole/3.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	眼前似乎有片煙霧四處擴散，不知哪來那麼多煙霧，五尺內景像皆
	看的矇矓不切，只見牆上模模糊糊的刻有幾個字"危險!莫入!"霎那
	間週圍殺氣迅速膨脹，是生是死，一切只有各安天命!!

LONG	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"4",
  "south":__DIR__"5",
  "west":__DIR__"2",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
