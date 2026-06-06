// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "崑崙山頂");
	set("long", @LONG
偌大的銀色山谷，終年白雪皚皚，地上還積
了一層薄薄的雪，雖是如此還是長了不少的花草
，你到處找找說不定還能找到一些珍貴的藥物。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"m6",
	"south" : __DIR__"m8",
]));
	set("outdoors", "1");

	setup();
}
