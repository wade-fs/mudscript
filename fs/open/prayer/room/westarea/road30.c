//open/prayer/room/westarea/road30.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八達, 處處繁華. 往東北方可以
	到達聖火教的總壇. 西方則可以到達聖火教支部的"玉衡門"與
	"瑤光門" .北邊則是錢莊. 聖火教的分級制度非常明顯, 教主
	以下有[文武星君]的職等, 此兩人的學藝素養分別是一文一武
	, 造詣已然出神入化.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"r1-15.c",	//錢鋪
        "east":__DIR__"road21",		//街道
        "west":__DIR__"road23",		//街道
 
        ]) );
        
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/high-man3" : 1,		
        ]) );
    setup();
}
