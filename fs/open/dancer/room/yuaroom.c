// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "世外桃源");
	set("long", @LONG
眼前所見盡是一片炫目繽紛的景象，各種不知名的鮮花綻放出五
彩顏色，令人恍惚是否到了世外桃源。不遠的前方有一座典雅樸素的
小屋……

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/open/dancer/room/yuaroom2",
]));
	set("outdoors", "1");

	setup();
}
