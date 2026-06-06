
#include <room.h>
#include "/open/open.h"
inherit ROOM;
void create()
{
set("short","修練房");
set("long", @LONG

    在這四周佈滿了歷代兵器﹐在你面前有一中年人在那
習武﹐他手裡拿的兵器非常耀眼﹐使你眼睛都快張不開了
一席盔甲也耀耀動人﹐這麼高大挺拔的大個莫非就是反亂
軍首領嗎。。。

LONG
);
    set("exits", ([
   "north" : __DIR__"r37.c",
   "east"  : __DIR__"r35.c",
        ]) );
	set("light_up",1);
  set("valid_startroom", 1);
  set("no_magic", 1);
  set("no_transmit", 2);

        setup();
}
int valid_leave(object me, string dir)
{
if(dir=="north")

if((me->query("class")!="soldier")&&me->query("class")!="soldier")
return notify_fail("只有傭兵才可進去。\n");
  return ::valid_leave(me,dir);
}
 
