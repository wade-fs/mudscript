//測試COMBINED_ITEM的疊加

#include "/u/b/blazakira/fix/combined.c" //使用共用檔案的話 則函數不能重複 且因為不是系統檔案 所以不需要<>的括號
//inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
  set_name(HIG + "綠龍精元" + NOR, ({"green-dragon pill","pill"}) );
  set("long","綠龍身上取得的精元，傳聞中可暫時增加刀客的能力!!\n");
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
  if (me->query_condition("blade_pill")>0) {
//    return notify_fail("藥效未除無法再吃!!\n");
    message_vision("$n藥效未除無法再吃!!\n",me,ob);
    return 1;
  }
  message_vision(HIG + "$N吃下綠龍精元，能力突增!!\n" + NOR, me);
  me->add_temp("apply/blade",50);
  me->set_temp("g-pill",1);
  me->apply_condition("blade_pill",20);
  add_amount(-1);
  return 1;
}
