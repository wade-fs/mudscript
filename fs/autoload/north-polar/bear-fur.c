//更改使用者this_player()的判斷為environment() by blazakira 2011/9/24

#include <armor.h>
#include <ansi.h>
inherit PANTS;

void create()
{
  set_name(HIW + "北極熊皮" + NOR,({"bear-fur","fur"}) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","件");
    set("value", 1);
    set("long","北極熊身上的厚厚皮毛，可以抵抗外力衝擊。\n");
    set("wear_msg", HIC + "$N穿上$n" + HIC + "，雙腿肥肥的，真是滑稽到極點。\n" + NOR );
    set("unequip_msg", HIC + "$N脫下了$n" + HIC + "，感覺稍微輕盈了些...\n" + NOR );
    set("no_put",1);
    set("no_drop",1);
    set("no_sell",1);
    set("no_auc",1);
    set("no_give",1);
    set("no_steal",1);
    set("armor_prop/parry", 5);
    set("armor_prop/armor", 50);
    set("armor_prop/move", -10);
    set("armor_prop/defense", 30);
  }
  setup();
}

void init()
{
  object me,ob;
  ob=this_object();
  me=environment();

  if( !ob->query("boss") )
  {
    ob->set("boss",me->query("id"));
  }
}

int query_autoload()
{
  return 1;
}
