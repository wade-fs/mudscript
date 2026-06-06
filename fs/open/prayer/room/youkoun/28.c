//open/prayer/room/youkoun/28.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練功\房");
        set("long",@LONG

        練功房寬約四丈, 非常寬廣!!房中四處擺滿了兵器, 十八
        般武器樣樣俱全. 還有許多的木人樁, 專門用來訓練門生
        的基礎動作.

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "west":__DIR__"1",              //左護法
 
        ]) );
        set("no_fight", 1);
        set("light_up", 1);
  setup();
}

