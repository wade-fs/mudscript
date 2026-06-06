//open/prayer/room/westarea/road15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 北邊是往天機
	門, 南邊是往天璇門. 聖火教的令牌一共有六隻, 也就是俗稱
	的[聖火令]. 每隻的長短不一, 不過上面好像都刻有武學的心
	法.....
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road10",	//街道
	"south":__DIR__"road18",	//街道
	"east":__DIR__"road14",		//街道
 
        ]) );
        set("no_fight", 0);
        
  setup();
}
