// Room: /open/main/room/m23.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
	set( "build", 24 );
  set ("long", @LONG
西邊是一座高聳的山, 完全找不到路可以上去, 聽說有時會有
仙人出沒, 所有除了叫筆架山之外, 又有一個名稱叫飛來峰, 上面
有一個石頭有一個大大的腳印, 稱為仙跡岩, 只是向來只是傳說罷
了, 根本沒人上去過, 除非有特殊的福緣吧?!
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m15",
  "east" : __DIR__"r32",
  "south" : __DIR__"s25",
  "west" : __DIR__"house.c",
]));
  set("outdoors", "/open/main");

  setup();
}
