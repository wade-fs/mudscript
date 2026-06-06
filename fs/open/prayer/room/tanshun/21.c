//open/prayer/room/tanshun/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的西方, 有兩個弟子正在討論最近聖火教內發生
        的事情. 你仔細一聽, 原來是有個武功高強的師兄暫時隱
        居去了. 瞧他們講得口沫橫飛, 也不曉得是真是假..

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"17",            //練武場
        "south":__DIR__"27",            //練武場
        "east":__DIR__"20",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,              //弟子
  "/open/prayer/npc/trainee3" : 1,              //弟子
                
]));
     
  setup();
}
