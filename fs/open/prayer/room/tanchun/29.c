//open/prayer/room/tanchun/29.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練功\房");
        set("long",@LONG

	練功房寬約四丈，非常寬暢通!!房中四處擺滿了兵器
	，十八般武器樣樣具全．還有許多的木人樁，專門用
	來訓練門生的基礎功夫．

LONG);

        set("exits", ([ /* sizeof() == 1 */
        "east":__DIR__"3",	
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
   		
     
  setup();
}
