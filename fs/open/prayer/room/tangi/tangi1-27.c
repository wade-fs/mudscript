//open/prayer/room/tangi/tangi1-27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",
"天機門的練武場,練武場上的弟子正在練功\. 傳聞聖火教的武學共有三套,其中之一的
渾天寶鑑心法,是女媧娘娘所遺留下來的武學!!修習之後不但能增強本身的內力!!更能
發揮許\多另人嘆為觀止的驚人美技!!\n");

                set("outdoors", "/u/r/rence");
                set("exits", ([ /* sizeof() == 3 */
                "north":"/open/prayer/room/tangi/tangi1-22",            //練武場
        "south":"/open/prayer/room/tangi/tangi1-32",            //練武場
        "west":"/open/prayer/room/tangi/tangi1-26",             //練武場
         
        ]) );
                set("no_fight", 0);
                set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 2,              //弟子
                
]));
     
  setup();
}
