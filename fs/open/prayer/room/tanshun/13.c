//open/prayer/room/tanshun/13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        副門主不待在書房, 竟跑到這裡來了! 原來是有一件極機
        密的文件要私底下交待一位弟子去送! 看他們交頭接耳的
        樣子, 還真有那麼一點點機密的味道!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"12",            //副門主室
        "northeast":__DIR__"10",                
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/vice-chair" : 1,           
   "/open/prayer/npc/trainee3" : 1,             //弟子
                
]));
     
  setup();
}
