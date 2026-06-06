inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("u",({"gold boots","boots"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW + "oO@ѶǻȤѥɥ[WuҽsulC\n" + NOR);
   set("wear_msg", "$NN$nWA" + HIY + "ɹu" + NOR + "Oq$N}WoXjj~C\n");
   set("unequip_msg", "$NN$n汼A" + HIY + "ɹu" + NOR + "OqHuhC\n");
        set("unit", "");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
          set("armor_prop/armor",6);
        set("armor_prop/move",3);
        set("armor_prop/dodge", 3);
        }
        setup();
}
