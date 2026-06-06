//open/prayer/room/youkoun/16.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的正東方, 有兩個女弟子正在交換彼此的心得.
        你走進一聽, 只聽到模模糊糊的幾句 :" 你這樣子不行,
        一旦動作太大, 就會有側陋的問題.."

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"9",             //練武場
        "south":__DIR__"19",            //練武場
        "west":__DIR__"17",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee3" : 1,                //弟子
        "/open/prayer/npc/trainee3" : 1,                //弟子
                
]));
     
  setup();
}
