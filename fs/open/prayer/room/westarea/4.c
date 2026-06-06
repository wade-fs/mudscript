//open/prayer/room/westarea/4.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","攀霞嶺");
        set("long",@LONG

	曼麗山上的一座小山嶺, 眼前所見是一些簡樸的茅
	屋, 還有些牲畜在四處亂飛亂跑!!霞雲滿佈, 好一
	股世外桃源之氣息!!眼前這位是隱世高人的第二位
	徒弟, 他正在揮舞著手中的鞭子, 看來他的鞭法非
	常地高明呢!!

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "west":__DIR__"2",	
 
        ]) );
        set("light_up", 1);
        set("no_transmit",1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/high-man2" : 1,		
        ]));
  setup();
}
