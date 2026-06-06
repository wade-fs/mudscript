//open/prayer/room/tangi/tangi1-32.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",
"天機門的練武場,練武場上的弟子正在訓練腿力. 傳聞聖火教的武學共有三套,第三便
是乾坤大挪移的步法,是教主在東土所悟得的武學!!能夠巧妙的避開敵人的攻擊!!\n");

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "north":"/open/prayer/room/tangi/tangi1-27",		//練武場
	"west":"/open/prayer/room/tangi/tangi1-31",		//練武場
       
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
