//open/prayer/room/youkoun/19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的東南方, 一個新入門的女弟子正在請教師姊生
        活上的問題. 看來她還不習慣過團體的生活, 而對於門主
        交待的 "一定要痛恨男性" 也是滿腹狐疑..

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"16",            
        "west":__DIR__"20",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
