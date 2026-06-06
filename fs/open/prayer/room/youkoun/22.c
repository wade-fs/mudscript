//open/prayer/room/youkoun/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","密道");
        set("long",@LONG

        原來這裡是一條密道, 密道內有一股很奇怪的臭味直撲鼻
        而來, 密道內燈光昏暗異常, 實在不像是一個崇拜火燄之
        神的教派應有的情景!!密道中鬼影幢幢, 你還是不要冒著
        危險強行進入比較好!!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"23",    
        "east":__DIR__"3",      
 
        ]) );
        set("no_fight", 0);
                
  setup();
}
