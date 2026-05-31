// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(MAG"忍者血手"NOR,({"ninja hands","hands"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "雙");
    set("value",0);
    set("long","傳說中會吸取敵人生命的血手套。\n");
    set("material","steel");
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
  this_object()->set("armor_prop/armor", 15);
  this_object()->set("armor_prop/attack", 15);
  this_object()->set("armor_prop/dodge",5);
  this_object()->set("armor_prop/parry",5);
  this_object()->set("armor_prop/dagger",20);
  this_object()->set("armor_prop/throwing",20);
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
  if( me->is_fighting() && query("equipped"))
  {
    if(random(100) > 85)
    {
      message_vision(RED"\n$N手中的血手發出紅光, $N瞬時精神一振, 全身充滿殺氣。\n"NOR,me);
      me->receive_curing("kee",100);
      me->receive_heal("kee",100);
      me->add("bellicosity",50);
    }
  }
}

int query_autoload()
{
  return 0;
}
