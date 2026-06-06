//排版 與更改eat_pill函數名稱為do_eat by blazakira 2011/11/3

inherit COMBINED_ITEM;

void create()
{
  set_name("五毒解藥", ({"five_medicine"}) );
  set("long","這是一顆用來解五毒的藥丸。\n");
  set("base_unit", "粒");
  set("unit", "粒");
  set("no_sell",1);
  set("value",2500);
  set_amount(1);
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object ob,me=this_player();
  if( !arg )
    return 0;
  if( !ob = present(arg,me) )
    return 0;
  if( ob != this_object() )
    return 0;
  message_vision("$N吃下五毒的解藥。\n", me);
  me->apply_condition("five_poison", 0);
  add_amount(-1);
  return 1;
}
