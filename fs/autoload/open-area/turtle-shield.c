//更改使用者的判定為me = environment(this_object()) by blazakira 2011/7/20

#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
  set_name(HIR"火龜殼盾"NOR,({"fire-turtle shield","shield"}) );
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","件");
    set("value", 1);
    set("long","火龜身上的硬殼, 恰巧可以用來抵禦攻擊。\n");
    set("no_put",1);
    set("no_drop",1);
//    set("no_get",1);
    set("no_sell",1);
    set("no_auc",1);
    set("no_give",1);
    set("no_steal",1);
  }
  setup();
  set("armor_prop/parry", 5);
  set("armor_prop/armor", 100);
  set("armor_prop/defense", 40);
}

void init()
{
  object me,ob;
  ob=this_object();
  me=environment(ob);
  if( !ob->query("boss") )
  {
    ob->set("boss",me->query("id"));
  }
}

int query_autoload()
{
  return 1;
}
