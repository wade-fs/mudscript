// made by ccat
// gin_pill沒有藥性..
//排版 與更改eat_pill函數名稱為do_eat by blazakira 2011/11/3

inherit COMBINED_ITEM;

void create()
{
  set_name("還精丸", ({"gin pill","pill"}) );
  set("long",  "一粒還精丸，會將你的氣轉換成精，你可以吞下它(eat pill)。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("value", 150);
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
  int max,now,now1,kee1;
  object ob,me=this_player();
  if( !arg ) return 0;
  arg=lower_case(arg);
  if( !ob = present(arg,me) ) return 0;
  if( ob != this_object() ) return 0;
  message_vision("$N吃下一粒還精丸。\n", me);
  max = me->query("max_gin");
  kee1 = me->query("kee");
  if( kee1 > 40 )
  {
    me->add("kee",-30);
    me->add("gin",25);
  } else {
    write("你的氣太低無法轉換成精。\n");
  }
  now = me->query("gin");
  if(now > max)
  {
    me->set("gin",max);
    now = max;
  }
  add_amount(-1);
  return 1;
}
