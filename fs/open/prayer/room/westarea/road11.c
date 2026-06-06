//open/prayer/room/westarea/road11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 北邊是往天
	樞門, 南邊是往天權門. 西域自從聖火教入主以來, 已經好
	久沒有戰亂的發生了. 東邊遠望過去有一座高聳的山脈!!
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road8",		//街道
	"south":__DIR__"road16",	//街道
	"west":__DIR__"road12",		//街道
 
        ]) );
        set("no_fight", 0);
        
  setup();
}
