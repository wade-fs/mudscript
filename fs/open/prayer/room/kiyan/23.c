//open/prayer/room/kiyan/6.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練功\房");
        set("long",@LONG

	練功\房寬約四丈，非常寬暢通!!房中四處擺\滿了兵器，十八般武
	器樣樣具全．還有許\多的木人樁，專門用來訓練門生的基礎功\夫．

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"5",		//左護法
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
  setup();
}

