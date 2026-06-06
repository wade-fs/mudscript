//u/r/rence/room/zhenche/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        這裡是議事廳的正中央, 四週站著陣勢門內的各高級主管
        , 有的正在向門主報告負責的事項, 有的則等待門主的最
        新指示.

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"2",             //議事廳
        "south":__DIR__"8",             //議事廳
        "east":__DIR__"4",              //議事廳
        "west":__DIR__"6",              //議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
   setup();
}
