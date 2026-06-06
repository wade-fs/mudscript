// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "環山長廊");
	set( "build", 12 );
	set("long", @LONG
這長廊不知道有多長多高，環繞著山而上，直
入雲霧中。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"v10",
	"westup" : __DIR__"r2",
]));
	set("outdoors", "1");

	setup();
}
