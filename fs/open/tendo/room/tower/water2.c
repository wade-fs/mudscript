#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "瀑布");
	set("long",@LONG
一條瀑布由崖上俯衝而下，濺起了一陣陣的漣漪，瀑布中形成了
一道彩虹，水聲在湖中產生的拍擊聲，與山谷間的迴響，造成了紫薇
內的一大奇觀，蔚為壯觀。
LONG
	);
set("exits", ([ /* sizeof() == 2 */ 
"south" : "/open/tendo/room/tower/water.c",
"north" : "/open/tendo/room/tower/cave.c", 
]));
        set("outdoors",1);
	setup();
}



