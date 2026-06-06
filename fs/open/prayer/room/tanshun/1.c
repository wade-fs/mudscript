//open/prayer /tanshun/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天璇門大廳");
        set("long",@LONG

        整座大廳的裝潢除了風格端莊之外, 特別還有一股文人雅
        士的氣息. 壁上四處可見大型的潑墨畫, 更襯托出門主的
        氣質. 廳上所站立的是天璇門的右護法.

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"4",             //大廳
        "west":__DIR__"2",              //門主
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/right" : 1,           //右護法
]));
  setup();
}

