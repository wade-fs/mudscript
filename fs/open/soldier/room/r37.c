
#include "/open/open.h"
inherit ROOM;
void create ()
{
set ("short", "修行房");
set ("long", @LONG

    這個房間是專門給加入傭兵的玩家﹐練功的地方﹐和
放一些裝備ㄚ..或者釋放食物ㄚ..一些雜七雜八的地方﹐
如果你想住這～我是不會反對～。。。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r36.c",
]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_kill", 1);
  set("no_fight", 1);
  setup();
}
 void init()
{
add_action("do_spp","spp");
add_action("do_jump","jump");
}
int do_spp()
{
  object me;
  me = this_player();
  if(me->query("class")!="soldier")
 return notify_fail("只有職業傭兵能用。\n");
 me->move("/open/ping/room/road3");
  return 1;
}
int do_jump()
{
object me;
me=this_player();
if(me->query("class")!="soldier")
return notify_fail("只有職業傭兵能用。\n");
me->move("/open/soldier/room/r1.c");
return 1;
}
 
