// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
眼前有座道觀，上頭寫著崑崙道觀四字，是專
門教導人們入道修行的地方，如果你對於奇門遁甲
及養生之道有興趣的話，你可以在此找到你所想要
的。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"v3",
	"south" : __DIR__"cloister",
]));
	set("outdoors", "1");

	setup();
}
