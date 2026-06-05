//設計者 by test軍團長, code by blazakira 2011/8/19

#include <ansi.h>
inherit EQUIP;

void create()
{
  set_name(HIC + "馳" + HIM + "風" + HIR + "掣" + HIG + "電" + NOR,({"wind-lightning-boots","boots"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long",HIY + "由飛行石所打造而成的鞋子，相當輕巧，幾乎感覺不到重量，還有微風在四周流動。\n" + NOR);
    set("unit","雙");
    set("value",1750);
    set("material","crimsonsteel");
    set("armor_type","boots");
    set("armor_prop/armor",7);
    set("armor_prop/force",5);
    set("armor_prop/dodge",7);
    set("armor_prop/move",12);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1);
    set("wear_msg",HIG + "$N" + HIG + "穿上$n" + HIG + "，一股暖風圍繞在身邊久久不散，$N" + HIG + "感到身體輕飄飄的，行動更加快速。\n" + NOR);
    set("unequip_msg",HIR + "$N" + HIR + "脫下$n" + HIR + "，身邊的暖風慢慢飄散，消失在四周，$N" + HIR + "覺得身體變的更加笨重了。\n" + NOR);
  }
  setup();
}

void init()
{
  add_action("do_help","help");
}

int do_help(string str)
{
  if (str!="wind-lightning-boots") return 0;

  write(@Help
    裝備構思協助者：test軍團長。
Help
  );
  return 1;
}

int query_autoload()
{
  return 1;
}
