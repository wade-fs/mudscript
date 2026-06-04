// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(MAG + "忍者殺意手環" + NOR, ({"ninja bracelet","bracelet"}) );
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "串");
    set("material", "steel");
    set("value", 0);
    set("long","據說當殺意到達一定程度便能發揮神奇能力的手環。\n");
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
  this_object()->set("armor_prop/armor",10);
  this_object()->set("armor_prop/dagger",20);
  this_object()->set("armor_prop/throwing",20);
  //set_heart_beat(1);
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
  if(random(100) > 55 && me->query("bellicosity") > 5000 && me->is_busy())
  {
    message_vision(MAG + "\n$N憑藉強大的鬥氣掙脫了外界的束縛，行動恢復正常。\n" + NOR,me);
    me->add("bellicosity",-100); //機率太高了 所以額外增限 by blazakira
    me->delete_busy();
  }
}

int query_autoload()
{
  return 0;
}
