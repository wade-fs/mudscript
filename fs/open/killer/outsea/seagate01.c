inherit ROOM;
#include <ansi.h>
void create ()
{
set("short", "海斷層");
set("long",@LONG
這你的水壓把你的身體加重了一倍，每走一步，都覺得氣血損失了大半
，眼前有一個下沈的地形，似乎可以通往更深的海底，相對而言，水壓也似
乎有所改變。
LONG);
set("exits",([
"east":__DIR__"sea_a03",
"westdown":__DIR__"sea03",
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
if(!present("dragon_stone",me))
{
return notify_fail(HIC + "你被強力的海潮沖了回來。\n" + NOR);
}
else
{
message_vision(HIY + "$N運起強大的內力，使得水壓不置於壓迫其身。\n" + NOR,me);
me->add("force",-100);
return 1;
}
}
