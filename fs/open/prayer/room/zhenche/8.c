///u/r/rence/room/zhenche/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        議事廳是陣勢門成員討論問題的地方. 往南是天璇門的玄
        關 (open door). 往北則是到門主的寶座. 兩旁站著門內各
        高階幹部, 個個表情嚴肅, 專心地聽門主指示!

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"5",                     //議事廳
        "south":__DIR__"1-door",                //玄關
        "east":__DIR__"7",              //議事廳
        "west":__DIR__"9",              //議事廳
        ]) );

        set("light_up", 1);
        create_door("south","聖火刻紋木雕門", "north",DOOR_CLOSED);
   setup();
}
