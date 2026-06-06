#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name("Ya", ({"gold helmet", "helmet"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW + "oO@ѶǻȤѥɥ[WuҽsYaC\n" + NOR);
   set("wear_msg", "$NN$naWA" + HIY + "Ya" + NOR + "OqϧAFqC\n");
   set("unequip_msg", "$NN$nUA" + HIY + "Ya" + NOR + "ߤ@OqHuhC\n");
      set("armor_prop/armor",7);
   set("armor_prop/force",2);
        set("unit", "");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
