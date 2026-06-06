//僅排版 by blazakira 2011/8/1

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
//  seteuid(getuid());
  set_name(HIR + "夕霞紅紗" + NOR , ({ "sun_red_cloth","cloth" }) );
  set("long","一件華美的紅色衣裳，上面似乎殘留著夕霞之餘暉。\n");
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value", 80000);
    set("material", "cloth");
    set("type", 1); 
    set("armor_prop/armor",25);
    set("armor_prop/force",10);
    set("armor_prop/attack",5);
    set("armor_prop/magic",3);
    set("armor_prop/spells",3);
    set("wear_msg", HIR + "$N穿起了$n" + HIR + "一身的華麗盡在不言中，足以比美夕陽的殘暉。\n" + NOR);
    set("unequip_msg", HIR + "$N輕輕的卸下$n" + HIR + "﹐夕陽的殘暉也隨即消失。\n" + NOR);
  }
  setup();
}
