// Room: /open/capital/room/r05.c

inherit ROOM;

void create ()
{
  set ("short", "環宮大道");
	set( "build", 60 );
  set ("long", @LONG
你現在來到京城內的大街, 高聳的圍牆和華麗的基石, 北方的城樓
烘托出一股莊嚴肅穆的氣氛, 皇上所住的皇宮便位於北方, 而整齊寬敞
的街道更顯出北方皇宮的氣派。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"convert_room.c",
  "west" : __DIR__"r04",
  "east" : __DIR__"r07",
]));
  set("gopath", "east");

  setup();
}
