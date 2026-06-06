//open/prayer/room/westarea/2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","攀霞嶺");
        set("long",@LONG

	曼麗山上的一座小山嶺, 眼前所見是一些簡樸的茅
	屋, 還有些牲畜在四處亂飛亂跑!!霞雲滿佈, 好一
	股世外桃源之氣息!!兩側分別有一位男子在練功,
	北邊則是一位臉帶笑容的老者!!

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"5",	
        "south":__DIR__"1",	
        "east":__DIR__"4",	
        "west":__DIR__"3",	
 
        ]) );
        set("light_up", 1);
        set("no_transmit",1);
//        set("objects",([ /* sizeof() == 1 */
//  "/open/prayer/npc/high-man" : 1,		
//]));
  setup();
}
