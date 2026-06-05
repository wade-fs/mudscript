//既然是copy的 怎不乾脆刪除不開放的函數呢 刪除之 by blazakira 2011/9/16

#include <armor.h>
#include <ansi.h>
inherit ARMBANDS;
inherit SSERVER;

void create()
{
  set_name(HIG + "青龍護臂" + NOR,({"dragon-armband"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","件");
    set("value", 0);
    set("material","blacksteel");
    set("long","皇室所使用之護臂，有強大防護力及能力強化。\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
	set("no_save",1);
	set("wield_msg", HIG + "$N穿戴上青龍護臂，瞬間能力上升了不少!!!\n" + NOR);
    set("unwield_msg", YEL + "$N脫下青龍護臂覺得自身能力下降不少。\n" + NOR);
  }
  setup();
  set("armor_prop/move", 2);
  set("armor_prop/dodge",3);
  set("armor_prop/parry",4);
  set("armor_prop/armor",30);
  set("armor_prop/magic",30);
  set("armor_prop/force",30);
}

int query_autoload()
{
  return 1;
}
