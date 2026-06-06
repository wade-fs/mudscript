// made by roger
//非賣品,攜帶之mob exp 170萬

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
  set_name(HIY + "九轉熊蛇丸" + NOR, ({"snake pill","pill"}) );
  set("long", "逍遙派聖藥，具有神奇無比的療效，幾可起死回生。\n");
  set("unit", "盒");
  set("base_unit", "粒");
  set("value", 30000);
  set("base_weight", 50);
  set_amount(1);
  setup();
}

void init()
{
  if( this_player()==environment() )
    add_action("eat_pill", "eat");
}

int eat_pill(string arg)
{
  int maxkee;
  object ob,me=this_player();
  maxkee=me->query("max_kee",1);
  if( !arg ) return 0;
//  arg=lower_case(arg);
//  if( !ob = present(arg,me) ) return 0;
//  if( ob != this_object() ) return 0;
  if(arg == "pill" || arg == "snake pill") {
    if(me->query("kee") >= maxkee) {
      message_vision("對$N來說" + HIY + "九轉熊蛇丸" + NOR + "已經沒有效果。\n", me);
      return 1;
    }
    message_vision("$N吃下一粒" + HIY + "九轉熊蛇丸" + NOR + "，只覺一股暖意從丹田升起。\n", me);
    me->set("kee",maxkee);
    me->set("eff_kee",maxkee);
    add_amount(-1);
    return 1;
  }
  return 0;
}
