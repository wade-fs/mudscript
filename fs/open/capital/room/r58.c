// Room: /open/capital/room/r58.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
	set( "build", 12 );
  set ("long", @LONG
這裡往北可以到達布政司，其專門管理城內柴米油鹽醬醋茶以及房
屋租售的問題，若你想買個家, 或是想找地方創個幫派, 這裡將會提供
你完整的資訊。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"M10",
  "west" : __DIR__"r56",
  "east" : __DIR__"r59",
]));
  set("shoyr", "雲洋大街");
  set("outdoors", "/open/capital");

  setup();
}
