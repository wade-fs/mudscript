//open/prayer/room/youkoun/10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的北方階梯上, 站著一位女總教頭! 她正為了這
        次三年一度的比武大會, 嚴格地指導著門生練習! 並不時
        地改正門生的動作 :" 當敵人來得好多好突然時.. "
        往北是議事廳, 往兩旁則分別通往副門主與總管房間.

LONG);

        set("outdoors", "/open/prayer");
        set("no_fight", 0);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"4",             //玄關
        "south":__DIR__"17",            //練武場
        "east":__DIR__"9",              //走廊
        "west":__DIR__"11",             //走廊
 
        ]) );
        
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-officer2" : 1,                //總教頭
                
]));
        
          setup();
}
