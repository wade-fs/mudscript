//open/prayer/room/zhenche/16.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        這裡是明教分部之一"陣勢門"的練武場, 練武場上總教頭
        正嚴厲地指導著門生們努力練習. 往北是天璇門的玄關,
        兩側的走廊是分別通往總管與副門主的辦公房.

LONG);
        set("outdoors", "/open/prayer/room");
        set("no_fight", 0);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"1-door",                //玄關
        "south":__DIR__"20",            //練武場
        "east":__DIR__"15",             //走廊
        "west":__DIR__"17",             //走廊
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general-officer" : 1,               //總教頭
                
]));
        
          setup();
}
