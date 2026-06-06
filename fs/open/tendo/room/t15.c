// Room: /open/tendo/room/t06.c

inherit ROOM;

void create()
{
	set("short", "修行房");
	set("long", @LONG
廣闊的地板鋪蓋著厚厚的草蓆，上面擺放著數個
蒲團，四周空盪盪的，沒有任何雜物。正有幾名天道
弟子坐在這兒修行。

LONG
	);
	set("objects",([
	"/open/tendo/npc/boy2" : 2,
	]));
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"t12",
]));
	set("light_up",1);
	setup();
}
