inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIM"醃漬桃子"NOR, ({"bellup pill","pill"}) );
	set("long","乾乾扁扁的桃子，看來已經存放許\多年了，你不能確定它是否\n可以食用(eat)。不過你可以確定的是它隨時都會風化。\n");
	set("unit", "盒");
	set("base_unit", "粒");
	set("no_auc",1);
	set("no_sell",1);
	set("no_give",1);
	set("no_sec",1);
	set("no_put",1);
	set("no_drop",1);
	set("no_steal",1);
	set("no_save",1);
	set("no_get",1);
	set("value",0);
	set_amount(1);
setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("eat_pill", "eat");
  }
}

int eat_pill(string arg)
{
	object ob,me=this_player();
	int bellup;
	if( !arg )                      return 0;
	arg=lower_case(arg);
	if( !ob = present(arg,me) )     return 0;
	if( ob != this_object() )       return 0;
	tell_object(me,"你吃下之後覺得一陣苦澀滋味在嘴裡發酵，突然間你感到心中的殺意不斷地狂飆。\n");
	me->add("bellicosity",1000);
	add_amount(-1);
	return 1;
}
