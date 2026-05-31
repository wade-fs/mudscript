// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
  set_name(MAG"忍者護盾"NOR,({"ninja shield","shield"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","材質輕巧利於閃躲且防禦力極高的封印盾牌。\n");
    set("unit","件");
    set("value",0);
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
  this_object()->set("armor_prop/armor",15);
  this_object()->set("armor_prop/parry",10);
  this_object()->set("armor_prop/dodge",10);
  this_object()->set("armor_prop/defense",30);
}

int query_autoload()
{
  return 0;
}
