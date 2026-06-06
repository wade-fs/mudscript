inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
set_name(HIC"藍龍精元"NOR, ({"blue-dragon pill","pill"}) );
set("long","藍龍身上取得的精元, 傳說中可暫時增加內力!!\n");
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
if (me->query_condition("power_pill") > 0)
return notify_fail("藥效未除無法再吃!!\n");
message_vision(HIC"$N吃下藍龍精元, 勁力突增!!\n"NOR, me);
me->add_temp("apply/force",25);
me->set_temp("b-pill",1);
me->apply_condition("power_pill",20);
add_amount(-1);
return 1;
}
