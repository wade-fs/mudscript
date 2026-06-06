//末日火山 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "火山口");
  set ("long", @LONG
終於在到達了烈焰環伺的山頂，岩漿從猶如煉獄洪爐般的火山口
不斷地溢出，攝人高溫幾欲使人暈厥，然而在融岩海內似乎另有一片
天地，要鼓起勇氣下去看看嗎?
LONG);

  set("exits", ([
  "down" : __DIR__"fire-temple.c",
  "southdown" : __DIR__"fmount2.c",
               ]));
  set("outdoors", "/open/main");
  set("no_transmit",1);
  setup();
}

void init()
{
 object me = this_player();
 if(me->query("attribute") != "fire")
  {
    me->add("gin",-2*(me->query("max_gin"))/5);
    me->add("kee",-2*(me->query("max_kee"))/5);
    me->add("sen",-2*(me->query("max_sen"))/5);
  }
}
