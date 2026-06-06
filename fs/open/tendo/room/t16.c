// Room: /open/tendo/room/t06.c

inherit ROOM;

void create()
{
	set("short", "修行房");
	set("long", @LONG
地板鋪著一層層的草蓆。四周相當地寬敞，沒有
其他的雜務擾人，是個冥想的好地方。你可以看到不
少的天道弟子坐在這冥想打坐。

LONG
	);
	set("objects",([
	"/open/tendo/npc/boy.c" : 2,
	]));
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"t06",
	"west" : __DIR__"t15",
	"south" : __DIR__"t14",
]));

	set("light_up",-1);
	setup();
}
