#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
   set_name("[1;31m[1;33m[1;31m[1;33m[1;31m[1;33m[1;31m[1;33m[0m" ,({"gold cloth","cloth"}));
   set_weight(30000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
   set("unit","");
   set("value",150000);
   set("material", "cloth");
   set("long",HIW + "oO@ѶǻȤѥɥ[Wuҽs_C\n" + NOR);
   set("wear_msg", "$NN$nWA" + HIY + "" + NOR + "Oqe`b$NC\n");
   set("unequip_msg", "$NN$n汼A" + HIY + "" + NOR + "OqHuhC\n");
set("armor_prop/armor",22);
   set("armor_prop/force",3);
   set("armor_prop/unarme",3);
   set("armor_prop/dodge",-5);
}
        setup();
}
