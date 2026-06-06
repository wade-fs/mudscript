// Room: /d/oldpine/epath2.c

inherit ROOM;

void create()
{
	set("short", "古木夾道");
	set("long", @LONG
你走在蜀山小徑上,四周都是百年的古榕,參差交雜的枝幹遮
敝了天空,卻擋不住涼涼的風透入,你在樹陰下行走,踩著枯黃的落
葉,心想: 好個蜀州的綠色隧道...
LONG
	);
	set("exits", ([
     "east" : __DIR__"road3.c",
     "west" : __DIR__"road1.c",
]));
	setup();
}


