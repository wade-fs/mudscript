//open/prayer/room/westarea/road23.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	這裡是西域西邊的三叉路口. 北邊是往天璇門, 南邊是往玉
	衡門. 傳聞西邊的曼麗山以前也有個洞窟, 不過現在好像是
	進不去了...........
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road18",	//街道
	"south":__DIR__"road26",	//街道
	"east":__DIR__"road22",		//街道
 
        ]) );
        set("no_fight", 0);
        
  setup();
}
