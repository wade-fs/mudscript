//調整drink的訊息與使用者的判定 by blazakira 2011/6/2

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
  set_name(HIY"千年花蜜"NOR, ({"thousand nectar","nectar"}) );
  set("long","千年花精淡情悠修練千年所粹取出來的花蜜，能提升內力和真氣。\n");
  set("base_unit", "瓶");
  set("unit", "瓶");
  set("no_sell",1);
  set("no_steal",1);
  set("no_sac",1);
  set("value",90000);
  set_amount(1);
  setup();
}

void init()
{
  add_action("drink_nectar", "drink");
}

int drink_nectar(string arg)
{
  object ob,me=environment(this_object());
  if( !arg )
    return 0;
  if( !ob = present(arg,me) )
    return 0;
  if( ob != this_object() )
    return 0;
  if ( me->query_condition("nectar") > 0 ) {
//    return notify_fail("你已經吃過了，再吃一次很浪費的!!\n");
    message_vision("你已經吃過了，再吃一次很浪費的!!\n",me,ob);
    return 1;
  }
  message_vision(HIY"$N一口氣喝光了一瓶的$n"HIY"，只見$N"HIY"真氣迅速提升並緩緩從身上散發出來!!\n"NOR,me,ob);
  me->add("force",20000);
  me->apply_condition("nectar",100);
  add_amount(-1);
  return 1;
}

