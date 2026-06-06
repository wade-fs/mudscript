//open/prayer/room/westarea/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","攀霞嶺");
        set("long",@LONG

	曼麗山上的一座小山嶺, 眼前所見是一些簡樸的茅
	屋, 還有些牲畜在四處亂飛亂跑!!霞雲滿佈, 好一
	股世外桃源之氣息!!眼前這位便是聖火教副教主的
	結拜義兄了!!哇, 果真有緣相見, 是不是該向他道
	謝相救之恩呢??

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"2",	
 
        ]) );
        set("light_up", 1);
        set("no_transmit",1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/high-man" : 1,		
        ]));
  setup();
}
