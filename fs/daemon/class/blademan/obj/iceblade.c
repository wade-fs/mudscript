// blade.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
set_name(HIC + "雪影" + NOR,({"iceblade","blade"}));
set_weight(19000);
if(clonep())
set_default_object(__FILE__);
else {
set("unit", "把");
set("value",70000);
set("weapon_prop/dodge",10);
set("weapon_prop/parry",10);
set("weapon_prop/move", 5);
set("material", "steel");
set("long", @LONG

雪影乃是一把稀世寶刀，刀身上陣陣透出寒氣讓人感覺出它的威力。
聽說世上只有一把劍能與之抗衡，但這把劍還不知道是哪一把！
LONG
);
set("wield_msg","$N抽出寒氣透骨的$n握在手中，$N的手瞬間的矇上一層霜，$N感覺到$n無匹的力量注入$N的體內。\n");
set("unwield_msg","$N將$n插回背後的纏刀布中。\n");
	}
init_blade(85);
set("ski_type1","blade");
set("ski_type2","dragon-blade");
set("ski_level1", 100);
set("ski_level2", 110);
	setup();
}
