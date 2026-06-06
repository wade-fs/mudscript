#include <ansi.h>
inherit ROOM;
void create ()
{
set("short","深溝");
set("long",@LONG
水壓越來越強了，你連抬起腳來都覺得痛苦，每走一步，氣血就急速
下降，或許你已經來不及回去了，在缺養的狀態下，你慢慢有了昏炫的感
覺。
LONG);
set("exits",([
"north":__DIR__"sea_out1",
"south":__DIR__"sea_out1",
"west":__DIR__"sea_out1",
"east":__DIR__"sea_out1",
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
