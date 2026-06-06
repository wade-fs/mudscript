// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "崑崙山頂");
	set("long", @LONG
這長廊不知道有多長多高，環繞著山而上，直
入雲霧中。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"westdown" : __DIR__"r3",
	"north" : __DIR__"m1",
	"up" : __DIR__"cloud",
]));
	set("outdoors", "1");

	setup();
}
