// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira 2011/7/28

#include <armor.h>
#include <ansi.h>
inherit PANTS;

void create()
{
  set_name(MAG "忍者夜行褲" NOR, ({ "ninja pants" ,"pants" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value", 0);
    set("long","以堅韌的黑色蠶絲織成, 輕巧且防護力高。\n");
    set("material", "steel");
    set("armor_prop/armor", 30);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
//    set("no_drop",1);
    set("no_get",1);
    set("no_save",1);
    set("need_class","killer");
    set("armor_prop/dagger", 10);
    set("armor_prop/throwing", 10);
    set("armor_prop/move", 20);
    set("armor_prop/dodge", 20);
  }
  setup();
}

int query_autoload()
{
  return 0;
}
