// Room: /open/main/room/r18.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set( "build", 22 );
	set("long", "從這兒你可以看到南邊高聳直立的筆架山, 北邊綿延千里的蜀
山, 傳說中, 蜀山常常有劍仙出沒, 一飛就飛到筆架山, 因此這兒
的人們在耕種之餘, 也養成抬頭看天的習慣. 道路在此呈南北走向
, 南方則是凌雲村.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"r11",
  "south" : "/open/start/room/s9",
  "east" : __DIR__"m8",
  "southwest" : __DIR__"b1",
]) );

  set("outdoors", "/open/main" );


  setup();
}
