inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
set_name(HIY + "黃龍精元" + NOR, ({"yellow-dragon pill","pill"}) );
set("long","黃龍身上取得的精元, 傳聞中可暫時增加劍士與書生的能力!!\n");
set("base_unit", "粒");
set("unit", "粒");
set("no_sell",1);
set("no_steal",1);
set("value",99000);
set_amount(1);
setup();
}
void init()
{
add_action("eat_pill", "eat");
}
int eat_pill(string arg)
{
object ob,me=this_player();
if( !arg )                     
return 0;
if( !ob = present(arg,me) )     
return 0;
if( ob != this_object() )       
return 0;
if (me->query_condition("sword_pill") >0)
return notify_fail("藥效未除無法再吃!!\n");
message_vision(HIY + "$N吃下黃龍精元, 能力突增!!\n" + NOR, me);
me->add_temp("apply/sword",50);
me->add_temp("apply/stabber",50);
me->set_temp("y-pill",1);
me->apply_condition("sword_pill",20);
add_amount(-1);
return 1;
}
