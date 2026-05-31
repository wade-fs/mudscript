// blade.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
    set_name(HIY"魚龍"NOR,({"ublade","blade"}));
    set_weight(10000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit", "把");
	set("value",20000);
	set("long", @LONG

這是把失傳的名刀『魚龍刀』，刀芒一直四射，使你的眼睛無法張開。
LONG
	);
	set("weapon_prop/dodge",5);
	set("weapon_prop/parry",5);
	set("weapon_prop/move",5);
	set("material", "steel");
	set("wield_msg","$N裝備$n，瞬時魚龍刀芒四射。\n");
	set("unwield_msg","$N小心亦亦的，將魚龍寶刀收好。\n");
    }
    init_blade(80);
    set("ski_type1","blade");
    set("ski_type2","dragon-blade");
    set("ski_level1", 90);
    set("ski_level2", 90);
    setup();
}
