//open/prayer/room/youkoun/27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","刑房");
        set("long",@LONG

        原來這裡就是瑤光門私設的刑房!!在西域民間的傳聞竟然
        是真的!!瑤光門主痛恨男人, 所以殘殺男性為樂??這裡的
        刑具都很奇怪, 還有好多是你從未見過的用具有!!天呀!!
        身為男性的人還不趕快跑出去??

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"2",     
        "north":__DIR__"26",    
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/chamber" : 2,         //弟子
                
]));
                
  setup();
}
