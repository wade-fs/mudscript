// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "崑崙山");
	set("long", @LONG
平坦的石道到了這裡變成了較為崎嶇的石子路，兩
旁的樹木愈見稀少，往前望去只看到一條蜿蜒的羊
腸小徑，曲曲折折地通往山頂。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"v9",
	"north" : __DIR__"r1",
]));
	set("outdoors", "1");

	setup();
}
