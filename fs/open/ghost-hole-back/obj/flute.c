inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY + "旋音笛" + NOR, ({ "whirl sound flute","flute"}) );
	if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "枝");
        set("long", "這是一個亮黃色的長笛，傳說中在死靈幽谷中使用(g-use)，可以割破
空間。\n");
        set_weight(100);
        set("value",0);
	     }
}

void init()
{
add_action("do_use","g-use");
}

int do_use(string arg)
{
object me=this_player();
object ob=this_object();
object room=environment(me);
if(!arg||arg!="flute")
return notify_fail("你要使用什麼東西？\n"); 
if(!room->query("ghost-hole/can_use_flute"))
return notify_fail(HIW + "此笛子只能在死靈幽谷的白洞使用。\n" + NOR);
if(!me->query_temp("ghost-hole/evil-ghost-flute"))
{
message_vision(HIR + "$N吹奏出十分難聽的聲音，旋音笛沒多久就斷裂了！！\n" + NOR,me);
destruct(ob);
return 1;
}
message_vision(HIY + "$N突感殺戮之苦、分離之痛，笛聲高底起伏不已，瞬間笛聲割破了空間，一
下子$N被吸了進去！！\n" + NOR,me);
me->move("/open/ghost-hole/g-r01");
message_vision(HIW + "一到淒涼的笛聲傳至，空間突然出現了一道裂痕，$N從空間的裂縫中走了出
來！！\n" + NOR,me);
message_vision(HIR + "$N手上的" + HIY + "旋音笛" + HIR + "由於耗費了極大的能源，漸漸的化成了一推廢灰了...\n" + NOR,me);
destruct(ob);
return 1;
}
