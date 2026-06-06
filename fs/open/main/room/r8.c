// Room: /open/main/room/r8.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 7264 );
  set ("long", @LONG
從這兒你可以看到南邊高聳直立的筆架山, 北邊綿延千里的蜀
山, 傳說中, 蜀山常常有劍仙出沒, 走在這條路上的人, 大多是響
往著劍仙劍俠的事蹟而來的, 也有人是為了尋寶, 總之, 人人手上
都拿把武器, 看來_成仙_果然很快, 不過大概是被人抬去種的模樣
罷了. 道路在此則通往東方或南方.
LONG);

 
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m1",
  "south" : __DIR__"r11",
  "west" : __DIR__"f10",
  "east" : __DIR__"r9",
]));

  setup();
}


