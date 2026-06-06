inherit ITEM;
#include <ansi.h>
void create()
{
set_name("海漩渦",({"whirlpool"}));
set("no_get",1);
set("no_sac",1);
setup();
}
void init()
{
object me;
me=this_player();
if(present("dragon_stone",me))
{
message_vision(HIY + "\n\n來至遙遠的中原人士"HIR+me->query("name")+HIY"啊！請讓我為你服務吧！\n\n" + NOR,me);
destruct(present("dragon_stone",me));
me->start_busy(4);
call_out("s_msg",1,me);
}
}
int s_msg(object me)
{
message_vision(HIB + "\n\n海漩渦猛然向$N衝了過來，$N整個人被包圍在海漩渦的中心。\n\n" + NOR,me);
call_out("s_msg2",2,me);
return 1;
}
int s_msg2(object me)
{
message_vision(HIY + "\n\n$N的身體猶如抹布一般的扭曲於漩渦中，向上直旋。\n\n" + NOR,me);
me->move(__DIR__"island/island");
message_vision(HIR + "\n\n$N被海漩渦給送到這裡。\n" + NOR,me);
return 1;
}
