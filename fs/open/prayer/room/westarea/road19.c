//open/prayer/room/westarea/road19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 北邊是往天權門
	, 南邊是往開陽門. 東邊則是"破邪洞窟". 傳聞裡面有許多的奇
	異怪獸, 至於如何的奇異, 那你要去問生還者才會知道了.
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
       	"north":__DIR__"road16",	//街道
	"south":__DIR__"road24",	//街道
	"west":__DIR__"road20",		//街道
	"east":"/open/prayer/room/hole/1",	//洞窟
 
        ]) );
        set("no_fight", 0);
        
  setup();
}
