// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(MAG + "忍者治癒戒" + NOR,({"ninja ring","ring"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("value",0);
    set("long","傳說中能讓佩帶者在休息時迅速恢復體力的戒指。\n");
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
  this_object()->set("armor_prop/armor", 5);
  this_object()->set("armor_prop/attack", 5);
  this_object()->set("armor_prop/dodge",5);
  this_object()->set("armor_prop/parry",5);
  this_object()->set("armor_prop/dagger",10);
  this_object()->set("armor_prop/throwing",10);
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
  if( !me->is_fighting() && query("equipped") )
  {
    if(random(100) > 75)
    {
      me->receive_curing("kee",10);
      me->receive_heal("kee",10);
    }
  }
}

int query_autoload()
{
  return 0;
}
