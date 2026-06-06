//open/prayer/room/youkoun/11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的西北角落, 有位師姊正在個別指導師妹的動作
        . 瞧她說得很認真的樣子, 可惜師妹還是一知半解..從這
        往西是通往總管房的走廊.

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"10",             
        "south":__DIR__"18",            //練武場
        "west":__DIR__"13",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
