// made by ccat
//排版 與更改eat_pill函數名稱為do_eat by blazakira 2011/11/3

inherit COMBINED_ITEM;

void create()
{
  set_name("百花清心露", ({"flower pill","pill"}) );
  set("long","一粒百花清心露，能剋百毒，你可以吞下它(eat pill)。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("value", 15000);
  set("base_weight", 50);
  set_amount(1);
  setup();
}

void init()
{
  if( this_player()==environment() )
    add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object ob,me=this_player();
  if( !arg ) return 0;
  arg=lower_case(arg);
  if( !ob = present(arg,me) ) return 0;
  if( ob != this_object() ) return 0;
  message_vision("$N吃下一粒百花清心露。\n", me);
  me->clear_condition();
  add_amount(-1);
  return 1;
}
