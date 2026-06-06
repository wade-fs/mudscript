//既然沒有心跳函數 就不使用set_heart_beat() by blazakira 2011/7/5

#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIY + "幸運草環" + NOR, ({ "lucky-grasslink","lucky" }));
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一個天靈界中流落在這世上的草環，據說可以讓穿載他的人能更快速\n"
      +"的收集天靈地界失落在這世上的個式各樣寶物。\n");
    set("unit", "頂");
    set("value", 1000000);
    set("material", "steel");
    set("no_steal",1);
    set("type", 1); 
    set("no_give",1);
    set("no_sell",1);
    set("armor_prop/armor", 15);
    set("armor_prop/dodge", 5);
    set("armor_prop/parry", 5);
    set("armor_prop/attack", 5);
    set("armor_prop/force", 5);
    set("wear_msg","$N戴上了$n，感覺由心中然起了一絲奇異的感覺!!\n");
    set("unequip_msg","$N卸下了$n，奇異的感覺也跟著消失了!!\n");
  }
  setup();
}

void init()
{
//  add_action("do_wear","wear");
  add_action("do_drop","drop");
  add_action("do_drop","auc");
//  add_action("do_drop","remove");
}
/*
int do_wear(string str)
{
  object ob=this_object(),user=environment();
  if( str == "lucky-grasslink" || str == "all" || str == "lucky" )
  {
    if ( query("equipped") ) 
    {
//      user = this_player(); // 取得使用者
      message_vision("$N戴上了$n，感覺由心中然起了一絲奇異的感覺!!\n",user,ob);
      user->set_temp("bless",1);
    }
  }
}
*/
int wear()
{
  object ob=this_object(),user=environment();
  int result = ::wear();
//  if(query("equipped") && environment(environment()))
  if( query("equipped"))
  {
//    message_vision("$N戴上了$n，感覺由心中然起了一絲奇異的感覺!!\n",user,ob);
    user->set_temp("bless",1);
  }
  return result;
}

int do_drop(string str)
{
  if( str=="lucky-grasslink" || str=="all" || str == "lucky" )
  {
    if( query("equipped") )
    {
      environment()->delete_temp("bless");
      message_vision("$N卸下了$n，奇異的感覺也跟著消失了!!\n",environment(),this_object());
    }
  }
}
/*
int do_remove(string str)
{
  if( str=="lucky-grasslink" || str=="all" || str == "lucky" )
  {
    if( query("equipped") )
    {
      user->delete_temp("bless");
      message_vision("$N卸下了$n，奇異的感覺也跟著消失了!!\n",user,ob);
    }
  }
}

int do_auc(string str)
{
  if(str=="lucky-grasslink" || str=="all" || str == "lucky" )
  {
    if( query("equipped") )
    {
	  user->delete_temp("bless");
	  message_vision("$N卸下了$n，奇異的感覺也跟著消失了!!\n",user,ob);
    }
  }
}
*/
