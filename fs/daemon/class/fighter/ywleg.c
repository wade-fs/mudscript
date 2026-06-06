#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
        set_name("",({"gold legging","legging"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW + "oO@ѶǻȤѥɥ[Wuҽs@C\n" + NOR);
   set("wear_msg", "$NN$nWA" + HIY + "Խ" + NOR + "_Oq$NPıYNC\n");
   set("unequip_msg", "$NN$n汼A" + HIY + "Խ" + NOR + "_Oqq$NWuhC\n");
        set("unit","");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
      set("armor_prop/armor",6);
        set("armor_prop/move",3);
        }
        setup();
}
