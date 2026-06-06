// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "崑崙山頂");
	set( "build", 12 );
	set("long", @LONG
你來到這兒，視野忽地廣闊開來。一眼望去
不再是奇石峋嶙的山道，卻是一個偌大的銀色山
谷，白雪皚皚，到處長滿了平地難得一見的花草
山谷之中還有一個天池，雖是平靜無波，但卻也
不凍不冰，十分奇特。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"r4",
	"east" : __DIR__"m2",
	"west" : __DIR__"m8",
	"north" : __DIR__"m6",
]));
	set("outdoors", "1");

	setup();
}
