//open/prayer/room/tanchun/19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	練武場上的弟子正在練功. 傳聞聖火教的武學共有三套, 其中
	之一的渾天寶鑑心法, 是女媧娘娘所遺留下來的武學!!修習之
	後不但能增強本身的內力!!更能發揮許多另人嘆為觀止的驚人
	美技!!不過聽說要得到渾天水晶才可以修練哩!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"15",		//練武場
	"south":__DIR__"25",		//練武場
	"west":__DIR__"20",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
