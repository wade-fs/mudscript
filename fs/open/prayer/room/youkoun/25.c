//open/prayer/room/youkoun/25.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","密道");
        set("long",@LONG

        密道內部傳來的哀號聲越來越大, 密道內的燈光從前面照
        射過來!!地上的肢體殘骸也越來越多, 腳踩在上面都會發
        出ㄗㄍ~~ㄗㄍ的聲音!!好刺耳啊!!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"26",     
        "west":__DIR__"24",     
 
        ]) );
        set("no_fight", 0);
                
  setup();
}
