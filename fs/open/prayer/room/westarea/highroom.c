//open/prayer/room/westarea/highroom.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","攀霞嶺");
        set("long",@LONG

	曼麗山上的一座小山嶺, 眼前所見是一些簡樸的茅
	屋, 還有些牲畜在四處亂飛亂跑!!霞雲滿佈, 好一
	股世外桃源之氣息!!往下走是下山的方向, 來到這
	裡難道就這樣下山去了??

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"1",	
        "down":__DIR__"road23",
 
        ]) );
        set("light_up", 1);
        set("no_transmit",1);
//        set("objects",([ /* sizeof() == 1 */
//  "/open/prayer/npc/high-man" : 1,		
//]));
  setup();
}
