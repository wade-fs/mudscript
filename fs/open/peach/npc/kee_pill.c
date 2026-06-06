inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(HIM + "靈氣桃子" + NOR, ({"s_kee pill","pill"}) );
	set("long","桃子上充滿著靈氣，好像可以轉換(change)桃子的靈氣總類，吃下去後，好像有特別的功\效。\n");
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
    add_action("do_change","change");
  }
}
int do_change(string arg)
{
  object me = this_player();

  if(!arg) {
	  tell_object(me,"你可以利用  change tiger/dragon/god 來轉換藥丸的靈氣。\n");
    return 1;
  }
  switch(arg)
  {
    case "tiger":
      if(me->query("quests/get_tiger")) 
      {
        tell_object(me,GRN + "藥丸在注入雷虎之氣後，裡面充滿著狂虎的氣息。\n" + NOR);
        set("sec_kee","tiger");
        return 1;
      }
        break;
    case "dragon":
      if(me->query("quests/dragon-kee")) 
      {
        tell_object(me,GRN + "藥丸在注入青龍之氣後，裡面充滿著青龍的氣息。\n" + NOR);
        set("sec_kee","dragon");
        return 1;
      }
        break;

    case "god":
      if(me->query("quests/sec_god")) 
      {
        tell_object(me,GRN + "藥丸在注入仙雲之氣後，裡面充滿著祥和的氣息。\n" + NOR);
        set("sec_kee","god");
        return 1;
      }
        break;

    break;
    default:
    tell_object( me , "沒有這種靈氣總類哦！\n");
    return 1;
  }
  tell_object(me , "你本身並沒有這種靈氣哦！\n");
  return 1;
}
int eat_pill(string arg)
{
	object ob,me=this_player();
	int bellup;
	if( !arg )                      return 0;
	arg=lower_case(arg);
	if( !ob = present(arg,me) )     return 0;
	if( ob != this_object() )       return 0;
if(!query("sec_kee")) return notify_fail("請先用change選好靈氣。\n");
	tell_object(me,HIG + "你吃下之後覺得桃子上的靈氣充滿全身。\n" + NOR);
  tell_object(me,"你的靈氣已經轉換了！\n");
	me->set("sec_kee",query("sec_kee"));
	add_amount(-1);
	return 1;
}
