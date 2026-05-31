#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name("[1;31mª[1;33m÷[1;31mÃ[1;33mó[1;31mÀ[1;33mY[1;31m±[1;33ma[0m", ({"gold helmet", "helmet"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"³o¬O¤@¥ó¥Ñ¶Ç»¡¤¤¥È¤Ñ¥É¥[¤Wª÷Ãó½u©Ò½s¦¨ªºÀY±a¡C\n"NOR);
   set("wear_msg", "$N±N$n±a¤W¡A"HIY"ª÷ÃóÀY±a"NOR"ªº¤O¶q¨Ï§A¤ßÆF³q©ú¡C\n");
   set("unequip_msg", "$N±N$n®³¤U¡A"HIY"ª÷ÃóÀY±a"NOR"ªº¤ß¤¤Å@«ùªº¤O¶qÀH¤§³u¥h¡C\n");
      set("armor_prop/armor",7);
   set("armor_prop/force",2);
        set("unit", "³»");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
