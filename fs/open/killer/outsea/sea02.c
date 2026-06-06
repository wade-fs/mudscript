#include <ansi.h>
inherit ROOM;
void create ()
{
set("short", "深溝");
set("long",@LONG
這你的水壓把你的身體加重了一倍，每走一步，都覺得氣血損失了大半
，再加上一大堆奇奇怪怪的魚在你身旁游著，或許你該趁著還未走遠，趕快
回頭吧。
LONG);
set("exits",([
"eastup":__DIR__"sea01",
"north":__DIR__"sea_a07",
"south":__DIR__"sea_a11",
"west":__DIR__"sea_a01",
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
