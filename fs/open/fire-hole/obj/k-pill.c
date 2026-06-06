inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
set_name(HIR + "龍王精元" + NOR, ({"dragon-king pill","pill"}) );
set("long","火龍王身上取得的精元, 傳說中可暫時獲得烈燄浩氣的威力!!\n");
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
if (me->query_condition("kang_pill") > 0)
return notify_fail("藥效未除無法再吃!!\n");
message_vision(HIR + "$N吃下龍王精元, 烈燄浩氣漸漸在體內產生!!\n" + NOR, me);
me->set_temp("kang-power",1);
me->apply_condition("kang_pill",20);
add_amount(-1);
return 1;
}
