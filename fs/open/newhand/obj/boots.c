// Qc by Anmy 98/7/6
//排版 by blazakira 2011/10/20

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name( HIG "狂想新人寶鞋" NOR ,({"newbie boots","boots"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "雙");
    set("value",1000);
    set("material","gem");
    set("armor_prop/armor",4);
    set("armor_prop/dodge",3);
    set("armor_prop/move",3);
    set("no_sell", 1); //不然就得多攔 action sell
    set("no_give",1);
    set("no_get",1);
    set("no_drop",1);
    set("no_auc",1);
  }
  setup();
}

int query_autoload() { return 0; }
