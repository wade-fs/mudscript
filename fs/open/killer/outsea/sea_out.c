#include <ansi.h>
inherit ROOM;
void create ()
{
set("short","深溝");
set("long",@LONG
這你的水壓把你的身體加重了一倍，每走一步，都覺得氣血損失了大半
，往四周眺望，一片死寂，景象一成不變，也沒有任何目標可以確定位置，
看來得小心迷路。
LONG);
set("exits",([
"north":__DIR__"sea_out",
"south":__DIR__"sea_out",
"west":__DIR__"sea_out",
"east":__DIR__"sea_out",
]));
setup();
}

void init()
{
object me;
me=this_player();
message_vision(HIY"$N誤入了深海漩渦之中, 強大的水流將$N捲的昏迷不醒....\n"NOR,me);
if(present("dragon_stone",me)) destruct(present("dragon_stone",me));
call_out("wake_up",30,me);
me->unconcious();
}

int wake_up()
{
object me=this_player();
me->move("/open/killer/outsea/sea01.c");
me->remove_call_out("revive");
me->revive();
me->set("gin",1);
me->set("kee",1);
me->set("sen",1);
me->set("force",0);
me->set("atman",0);
me->set("mana",0);
me->set("food",0);
me->set("water",0);
}
