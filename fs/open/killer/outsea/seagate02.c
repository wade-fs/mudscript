inherit ROOM;
#include <ansi.h>
void create ()
{
set("short", "深溝--海漩渦");
set("long",@LONG
一個巨大無比的海漩渦就在你眼前不斷的旋轉著，彷彿永遠不會停止，
這種自然界的力量，讓你看的目瞪口呆，彷彿是天神刻意製造的海底奇觀，
神奇無比。
LONG);
set("exits",([
"east":__DIR__"sea_b03",
"westup":__DIR__"sea_c01",
]));
set("no_transmit",1);
set("no_chome",1);
set("objects",([
__DIR__"dstone":1,
]));
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
