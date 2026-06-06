#include <ansi.h>
inherit ROOM;
void create ()
{
set("short", "深溝");
set("long",@LONG
水壓越來越強了，你連抬起腳來都覺得痛苦，每走一步，氣血就急速
下降，或許你已經來不及回去了，在缺養的狀態下，你慢慢有了昏炫的感
覺。
LONG);
set("exits",([
"north":__DIR__"sea_c06",
"south":__DIR__"sea_d01",
"east":__DIR__"sea_c04",
"west":__DIR__"sea_out1",
]));
set("no_transmit",1);
set("no_chome",1);
setup();
}
int valid_leave(object me,string dir)
{
me=this_player();
if(me->query_temp("put_water")!=1)
{
me->move("/open/killer/outsea/sea01.c");
return notify_fail(HIC"你因失去定水珠的保護而被強力的海潮沖走了。\n"NOR);
}
if(!present("dragon_stone",me))
{
return notify_fail(HIC"你被強力的海潮沖了回來。\n"NOR);
}
else
{
message_vision(HIY"$N運起強大的內力，使得水壓不置於壓迫其身。\n"NOR,me);
me->add("force",-200);
return 1;
}
}

void init()
{
object me;
me=this_player();
if(present("deep shark",environment(me)))
return ;
if(random(10)<10)
	  {
	  object mob;
	  message_vision(HIC"$N覺得身旁似乎有東西緩緩靠近地靠近....\n"NOR,me);
          mob=new(__DIR__"shark");
	  mob->move(environment(me));
	  mob->set("inv",15);
	  return ;
	  }
}

