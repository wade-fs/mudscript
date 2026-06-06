// Room: /open/main/room/F4.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set( "build", 48 );
	set("long", @LONG
這裡一望無際的密林，四週伸手只見四指, 往西似乎稍微透出點亮光
那邊的樹應該比較少一些吧? 南邊高高聳立著一座高山, 山頂不知是雲還
是雪, 一片白茫茫, 那裡難道是蜀山?
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"f4",
  "north" : __DIR__"F1",
  "east" : __DIR__"F5",
]));

	setup();
}
