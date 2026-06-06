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
"north":__DIR__"sea_b03",
"south":__DIR__"sea_b04",
"east":__DIR__"sea_b09",
"west":__DIR__"sea_b11",
]));
set("no_transmit",1);
set("no_chome",1);
setup();
}
int valid_leave(object me,string dir)
{
int sk;
me=this_player();
sk=me->query_skill("force");

if(present("octopus",environment(me)))
{
return notify_fail(HIR + "你被八爪章魚給檔了下來。\n" + NOR);
}

if(present("water ninja",environment(me)))
{
return notify_fail(HIR + "你被水忍給檔了下來。\n" + NOR);
}

if(me->query_temp("put_water")!=1)
{
me->move("/open/killer/outsea/sea01.c");
return notify_fail(HIC + "你被強力的海潮沖了回來。\n" + NOR);
}

if(!present("dragon_stone",me))
{
return notify_fail(HIC + "你被強力的海潮沖了回來。\n" + NOR);
}

else
{
message_vision(HIY + "$N運起強大的內力，使得水壓不置於壓迫其身。\n" + NOR,me);
me->add("force",-200);
return 1;
}

}

void init()
{
object me;
me=this_player();
if(present("water ninja",environment(me)))
return ;
if(random(10)<10)
	 {
	  object mob;
	  message_vision(HIC + "在$N眼前突然冒出一位水忍擋住了去路。\n" + NOR,me);
          mob=new(__DIR__"w_ninjia");
	  mob->move(environment(me));
	  mob->set("attitude","aggressive");
	  return ;
	  }
}

