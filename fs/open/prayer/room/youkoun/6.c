//open/prayer/room/youkoun/6.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        在辦公房的北邊散落了一地的文件, 有兩個女弟子正忙著
        撿起來重新整理. 看她們緊張的樣子, 想必如果被副門主
        看到, 免不了又是一頓罵了.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"7",             //副門主室
        "southeast":__DIR__"5",         
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee3" : 1,                //弟子
                
]));
     
  setup();
}

