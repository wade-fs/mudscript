#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	seteuid(getuid());
        set_name(HIM"邪刀"NOR,({"shi-blade","blade"}));
        set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",20000);
                set("weapon_prop/dodge", 5);
                set("weapon_prop/parry", 5);
		set("material", "steel");
                set("wield_msg","$N拔出了$n臉上散發出了更重的邪氣。\n");
                set("unwield_msg","$N還刀入鞘，臉上邪氣漸弱。\n");
	}
        init_blade(80);
         set("ski_type1","blade");
         set("ski_type2","dragon-blade");
         set("ski_level1", 90);
         set("ski_level2", 90);
         setup();
}
