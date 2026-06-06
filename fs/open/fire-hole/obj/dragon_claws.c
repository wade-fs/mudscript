// 火龍幻界龍的爪子..by obs
#include <weapon.h>
#include <ansi.h>
inherit UNARMED;

void create()
{
  seteuid(getuid());
  set_name(HIR"幻界龍爪"NOR,({"dragon claws","claws"}));
  set_weight(4500);
  if( clonep() )
                set_default_object(__FILE__);
        else {
  set("unit", "副");
  set("value",12000);
  set("sharp",10);
  set("material","crimsonsteel");
  set("ski_type","unarmed");
  set("no_put",1);
  set("no_drop",1);
  set("no_get",1);
  set("no_sell",1);
  set("no_auc",1);
  set("no_give",1);
  set("no_steal",1);
  }
  init_unarmed(100);
  setup();
}
void init()
{
     object me = this_player();
     if(me)
     set_name (HIR + me->name(1) + HIR"的幻界龍爪"NOR, ({ "dragon claws", "claws" }));
}

