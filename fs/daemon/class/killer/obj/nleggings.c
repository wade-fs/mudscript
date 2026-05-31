// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <ansi.h>
#include <armor.h>
inherit LEGGINGS;

void create()
{
  set_name(MAG"忍者護膝"NOR,({"ninja legging","legging"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","件");
    set("value",0);
    set("material","steel");
    set("long","為不明蠶絲製成，有很高的防護。\n");
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
  this_object()->set("armor_prop/armor", 10);
  this_object()->set("armor_prop/move",15);
  this_object()->set("armor_prop/dodge",15);
  this_object()->set("armor_prop/dagger",20);
  this_object()->set("armor_prop/throwing",20);
}

int query_autoload()
{
  return 0;
}
