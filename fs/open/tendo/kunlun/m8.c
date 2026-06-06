// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "崑崙山頂");
	set("long", @LONG
偌大的銀色山谷，終年白雪皚皚，地上積了
一層薄薄的雪，雖是如此還是長了不少平地難得
一見的花草，你到處找找說不定還能找到一些珍
貴的藥物。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"m1",
	"north" : __DIR__"m7",
	"west" : __DIR__"c0",
]));
	set("outdoors", "1");

	setup();
}
