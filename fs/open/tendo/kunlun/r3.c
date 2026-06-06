// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "環山長廊");
	set("long", @LONG
朦朧的雲霧，令人分不清時刻與方向，若要繼續往
上走，只有沿著山壁的方向向上行走了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"westdown" : __DIR__"r2",
	"eastup" : __DIR__"r4",
]));
	set("outdoors", "1");

	setup();
}
