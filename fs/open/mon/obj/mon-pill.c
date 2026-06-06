//調整drink的訊息與使用者的判定 by blazakira 2011/7/7

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
  set_name(HIW"千年靈芝仙丹"NOR, ({"thousand pill","pill"}) );
  set("long","由長白山千年靈芝所提煉出來的藥丸, 具有起死回生迅速恢復精氣神的功\效!!\n");
  set("base_unit", "粒");
  set("unit", "粒");
  set("no_sell",1);
  set("no_steal",1);
  set("no_sac",1);
  set("value",90000);
  set_amount(1);
  setup();
}

void init()
{
  add_action("eat_pill", "eat");
}

int eat_pill(string arg)
{
  object ob,me=environment(this_object());
  if( !arg )
    return 0;
  if( !ob = present(arg,me) )
    return 0;
  if( ob != this_object() )
    return 0;
  if ( me->query_condition("mon_pill") > 0 ) {
//    return notify_fail("你的體內仍然持續著長白山千年靈芝的藥效!!\n");
    message_vision("$N的體內仍然持續著$n的藥效!!\n",me,ob);
    return 1;
  }
  message_vision(HIW"$N吃下長白山千年靈芝仙丹, 精氣神迅速恢復中!!\n"NOR, me);
  me->receive_curing("kee",2000);
  me->receive_heal("kee",2000);
  me->receive_curing("gin",1000);
  me->receive_heal("gin",1000);
  me->receive_curing("sen",1000);
  me->receive_heal("sen",1000);
  me->apply_condition("mon_pill",10);
  add_amount(-1);
  return 1;
}
