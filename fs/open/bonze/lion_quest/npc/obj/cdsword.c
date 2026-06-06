#include <weapon.h>
#include <ansi.h>
#include <combat.h>
inherit SWORD;
void create()
{
set_name(HIW + "雲" + HIC + "龍" + HIR + "仙劍" + NOR,({"cloud-dragon sword","sword"}) );
set_weight(5000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("long","據說此劍為劍修雲龍天宮宮主的佩劍，被他封印了某種秘法在其中。\n");
set("value",1000);
set("material", "crimsonsteel");
set("rigidity",80);
       set("no_auc",1);
       set("no_sell",1);
       set("no_give",1);
       set("no_put",1);
       set("no_drop",1);
       set("no_sec",1);
       set("no_save",1);
set("wield_msg", "$N拔出$n,，從劍上隱隱傳來龍的低鳴聲。\n");
set("unwield_msg", "$N將手中$n收回腰間劍鞘，頓時像似從身體剝去某種力量。\n");
set("weapon_prop/sword",12);
}
init_sword(95);
setup();
}
