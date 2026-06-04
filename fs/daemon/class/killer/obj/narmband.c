// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <armor.h>
#include <ansi.h>
inherit ARMBANDS;

void create()
{
  set_name(MAG + "忍者臂甲" + NOR,({"ninja armband","armband"}) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","個");
    set("value",0);
    set("long","一件具有極高防護力的臂甲。\n");
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
  this_object()->set("armor_prop/armor", 50);
  this_object()->set("armor_prop/dodge", 15);
  this_object()->set("armor_prop/move", 15);
  this_object()->set("armor_prop/dagger", 15);
}

int query_autoload()
{
  return 0;
}
