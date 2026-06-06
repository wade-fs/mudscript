#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "通吃小築一樓");
  set ("long", @LONG

   這是由天才機關手諸岡渡與天靈老人，兩人合力完成的迷陣屋
   放眼望去每個房間長的都一樣，讓你難以分辨，到底要如何去行走？

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "west" : __DIR__"hr12.c",
     "down" : __DIR__"hr7.c",   
     "east" : __DIR__"hr8.c",   
     "north" : __DIR__"hr13.c",   
]));

 set("objects",([
  "/open/killer/npc/spy4.c":1,]));
  setup();
}

void init()
{
//
}

int do_look(string str)
{
  object me;

   if(str )
    return notify_fail("你想看什麼？？看看有沒有人救你嗎？？用哭的比較快啦！！\n");
   return 1;
}
