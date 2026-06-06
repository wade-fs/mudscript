//open/prayer/room/youkoun/24.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","密道");
        set("long",@LONG

        密道的四周有許多已經變黑的血跡, 那一股奇怪的臭味應
        該就是血腥味了, 密道內的燈光比剛才亮了一點!!哇~~地
        上都是一些肢體的殘骸, 看起來好像是手骨與腳骨!!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"25",     
        "south":__DIR__"23",    
 
        ]) );
        set("no_fight", 0);
                
  setup();
}
