//open/prayer/room/tangi/tangi1-25.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",
"天機門的練武場,練武場上的弟子正在練功\. 傳聞聖火教的武學共有三套,其中之一的
先天乾坤功\,威力無儔!!不過卻是需要不斷的練習!!\n");

        	set("outdoors", "/u/r/rence");
        	set("exits", ([ /* sizeof() == 3 */
        	"north":"/open/prayer/room/tangi/tangi1-20",		//練武場
	"south":"/open/prayer/room/tangi/tangi1-30",		//練武場
	"east":"/open/prayer/room/tangi/tangi1-26",		//練武場
         
        ]) );
        	set("no_fight", 0);
        	set("objects",([ /* sizeof() == 3 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
