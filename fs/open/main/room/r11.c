// Room: /open/main/room/r11.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 186 );
  set ("long", @LONG
從這兒你可以看到南邊高聳直立的筆架山, 北邊綿延千里的蜀
山, 傳說中, 蜀山常常有劍仙出沒, 走在這條路上的人, 大多是響
往著劍仙劍俠的事蹟而來的, 也有人是為了尋寶, 總之, 人人手上
都拿把武器, 看來明哲保身之道似乎比求仙之道重要哩! 道路在此
呈南北走向.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r18",
  "north" : __DIR__"r8",
  "east" : __DIR__"m2",
]));

  set("outdoors", "/open/main");

  setup();
}
