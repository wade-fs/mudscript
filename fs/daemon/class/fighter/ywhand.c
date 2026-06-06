inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("@",({"gold hands","hands"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIW + "oO@ѶǻȤѥɥ[WuҽsMC\n" + NOR);
        set("wear_msg", "$NN$nWA" + HIY + "M" + NOR + "OqqWģ~C\n");
        set("unequip_msg", "$NN$n汼A" + HIY + "M" + NOR + "OqqWuhC\n");
        set("unit", "");
        set("value",90000);
        set("material","cloth");
        set("armor_type", "hands");
        set("armor_prop/armor",12);
        set("armor_prop/unarme",2);
        set("armor_prop/attack",10);
        }
        setup();
}
