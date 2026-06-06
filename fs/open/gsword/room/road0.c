#include "/open/open.h"
inherit ROOM;

void create()
{
	set("short", "叉路口");
	set("long", @LONG
    這裡是蜀山小徑的叉路口,往西是七星塔,往南是昆明湖,向東可到
蜀中城,往北則通往蜀山的山中...
LONG
	);
	set("exits", ([
     "north" : __DIR__"road0.c",
     "west" : __DIR__"towerf.c",	
    "east":__DIR__"froad1",
     "south" : __DIR__"lake1.c" ,
]));
//        set("objects", ([
//             GW_NPC"sells2" : 1,
//             GW_NPC"visitor" : 1,
//          ]));  
	setup();
}


