//open/prayer/room/youkoun/17.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的正中央, 有兩個較早入門的弟子正在示範動作
        給一旁的師妹們看. 看她們的樣子, 似乎真有那麼兩下子
        , 一點也不是花拳繡腿, 看得你都技癢了..

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"10",            //練武場
        "south":__DIR__"20",            //練武場
        "west":__DIR__"18",             //練武場
        "east":__DIR__"16",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee3" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
