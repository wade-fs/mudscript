// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(MAG + "忍者護心石" + NOR , ({"ninja gem","gem"}) );
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "條");
    set("value", 0);
    set("material","steel");
    set("long","封印著強大的力量, 可以給佩帶者莫名的庇祐。\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
//    set("no_drop",1);
    set("no_get",1);
    set("no_save",1);
    set("need_class","killer");
  }
  setup();
  this_object()->set("armor_prop/dodge",15);
  this_object()->set("armor_prop/defense",30);
  this_object()->set("armor_prop/attack",15);
  this_object()->set("armor_prop/armor",20);
//  set_heart_beat(1);
}

int wear()
{
  int ret = ::wear();
  if( query("equipped"))
  {
    set_heart_beat(1);
  }
  return ret;
}

int unequip()
{
  int ret = ::unequip();
  if( !query("equipped") )
  {
    set_heart_beat(0);
  }
  return ret;
}

void heart_beat()
{
  object me = environment();
  if( !objectp(me) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  if( query("equipped") && me->query("bellicosity") > 1000 )
  {
    if(random(100) > 30)
    {
      me->receive_curing("kee",2);
      me->receive_heal("kee",2);
      me->receive_curing("gin",2);
      me->receive_heal("gin",2);
      me->receive_curing("sen",2);
      me->receive_heal("sen",2);
    }
  }
}

int query_autoload()
{
  return 0;
}
