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
"north":__DIR__"sea_d04",
"south":__DIR__"sea_d04",
"west":__DIR__"sea_d01",
"east":__DIR__"sea_d01",
]));
set("no_transmit",1);
set("no_chome",1);
setup();
}
int valid_leave(object me)

{
me=this_player();
message_vision(HIY"$N運起強大的內力，使得水壓不置於壓迫其身。\n"NOR,me);
me->add("force",-500);
return 1;
}

void init()
{
object me;
me=this_player();
if (random(3)==0)
{
message_vision(HIR"$N覺得四周的水壓漸漸壓的你喘不過氣來。\n"NOR,me);
me->receive_wound("kee",1000);
COMBAT_D->report_status(me);
}
if (random(3)==0)
{
message_vision(HIC"$N被強大水壓壓的頭昏腦脹。\n"NOR,me);
me->receive_wound("gin",1000);
me->receive_wound("sen",1000);
COMBAT_D->report_status(me);
}
if (random(3)==0)
{
message_vision(HIR"$N覺得四周的水壓漸漸壓的你喘不過氣來。\n"NOR,me);
me->receive_wound("kee",1000);
COMBAT_D->report_status(me);
}
}
