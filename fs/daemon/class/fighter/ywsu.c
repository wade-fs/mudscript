#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
        set_name("",({"gold surcoat","surcoat"}));
        set_weight(10000);
        set("armor_type","cape");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "");
        set("material","leather");
        set("value",100000);
   set("long",HIW + "oO@ѶǻȤѥɥ[WuҽsܭC\n" + NOR);
   set("wear_msg", "$NN$nܤWA" + HIY + "ܭ" + NOR + "Oqe`b$NA$NH߭WC\n");
   set("unequip_msg", "$NN$nhA" + HIY + "ܭ" + NOR + "OqHuC\n");
           set("armor_prop/armor",6);
   set("armor_prop/parry",3);
        }
        setup();
}
