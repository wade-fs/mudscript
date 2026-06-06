//uhen/1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","門主的閨房");
        set("long",@LONG

	門主的閨房中散發出處子般的幽香，雖然門主已經二十好
	幾了，可是還是堅守著自身的清白呢!!那軟綿綿的床舖真
	是引人暇思呀!!旁邊有一個小小的床頭櫃．難道裡面是放
	著她的貼身衣物??哇~~口水流出來了..........

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"4",		//門主
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
  setup();
}

