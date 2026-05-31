// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <ansi.h>
#include <armor.h>
inherit CAPE;

void create()
{
  set_name(MAG"忍者披風"NOR,({"ninja surcoat","surcoat"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value",0);
    set("material","steel");
    set("long","既帥氣能夠提高對背部防護的披風。\n");
    set("no_auc",1);
    set("no_give",1);
    set("no_sell",1);
    set("no_put",1);
//    set("no_drop",1);
    set("no_get",1);
    set("no_save",1);
    set("need_class","killer");
  }
  setup();
  this_object()->set("armor_prop/armor",20);
  this_object()->set("armor_prop/defense",20);
  this_object()->set("armor_prop/parry",5);
  this_object()->set("armor_prop/dodge",5);
}

int query_autoload()
{
  return 0;
}
