// Room: /open/capital/room/r48.c

inherit ROOM;

void create()
{
	set("short","昇平橋");
	set("long",@LONG
這有條小溪流過，因此搭了座橋。為了紀念幾十年的天下太平，皇
帝把這橋取為昇平。這是座白色的拱橋，兩邊的石欄雕刻得美侖美奐。
橋並不長，但是相當的寬，這是為了配合馳道而設計的。

LONG);



  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r49",
  "south" : __DIR__"r47",
]) );

  set("gopath", "south" );

  setup();
}
