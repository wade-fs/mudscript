#include <ansi.h>
inherit ROOM;
void create ()
{
set("short", "深溝");
set("long",@LONG
這你的水壓把你的身體加重了一倍，每走一步，都覺得氣血損失了大半
，往四周眺望，一片死寂，景象一成不變，也沒有任何目標可以確定位置，
看來得小心迷路。
LONG);
set("exits",([
"north":__DIR__"sea_a04",
"south":__DIR__"sea_a08",
"east":__DIR__"sea_out",
"west":__DIR__"seagate01",
]));
set("no_transmit",1);
set("no_chome",1);
setup();
}
int valid_leave(object me,string dir)
{
me=this_player();
if(present("octopus",environment(me)))
{
return notify_fail(HIR + "你被八爪章魚給檔了下來。\n" + NOR);
}
if(me->query_temp("put_water")!=1)
{
me->move("/open/killer/outsea/sea01.c");
return notify_fail(HIC + "你被強力的海潮沖了回來。\n" + NOR);
}
else
{
message_vision(HIY + "$N運起強大的內力，使得水壓不置於壓迫其身。\n" + NOR,me);
me->add("force",-100);
return 1;
}
}
void init()
{
object me;
me=this_player();
if(present("octopus",environment(me)))
return ;
if(random(10)<4)
	{
	  object mob;
	  message_vision(HIR + "在$N眼前突然一隻八爪章魚擋住了去路。\n" + NOR,me);
          mob=new(__DIR__"octopus1");
	  mob->move(environment(me));
	  mob->set("attitude","aggressive");
	  return ;
	  }
}
