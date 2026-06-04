// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
  set_name(MAG + "忍者鬥氣腰帶" + NOR, ({"ninja belt","belt"}) );
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "條");
    set("material", "steel");
    set("value", 0);
    set("long","傳說中可以迅速提昇佩帶者鬥氣的腰帶。\n");
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
  this_object()->set("armor_prop/attack",15);
  this_object()->set("armor_prop/armor",30);
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
  if( !me->is_fighting() && query("equipped"))
  {
    if(random(100) > 55 && me->query("force") < me->query("max_force")*2 && me->query("class")=="killer")
    {
      me->add("force",2);
    }
    if(random(100) > 55 && me->query("bellicosity") < me->query("max_force") && me->query("class")=="killer")
    {
      me->add("bellicosity",2);
    }
  }
}

int query_autoload()
{
  return 0;
}
