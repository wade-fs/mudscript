inherit ROOM;
#include <ansi.h>
void create ()
{
set("short", "淺攤");
set("long",@LONG
你漸漸覺得身邊的水壓變小了，光線漸漸射入你的眼簾，四周的景色越
來越清楚，你頓時有股如獲重生的感覺!!
LONG);
set("exits",([
"east":__DIR__"sea_c06",
"westup":"/open/killer/sea_town/beach01",
]));
setup();
}
int valid_leave(object me,string dir)
{
int sk;
me=this_player();

if(me->query_temp("put_water")!=1)
{
me->move("/open/killer/outsea/sea01.c");
return notify_fail(HIC + "你因失去定水珠的保護而被強力的海潮沖走了。\n" + NOR);
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
