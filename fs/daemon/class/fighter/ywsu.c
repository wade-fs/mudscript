#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
        set_name("[1;31mª[1;33m÷[1;31mÃ[1;33mó[1;31m©[1;33mÜ[1;31m­[1;33m·[0m",({"gold surcoat","surcoat"}));
        set_weight(10000);
        set("armor_type","cape");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "¥ó");
        set("material","leather");
        set("value",100000);
   set("long",HIW"³o¬O¤@¥ó¥Ñ¶Ç»¡¤¤¥È¤Ñ¥É¥[¤Wª÷Ãó½u©Ò½s¦¨ªº©Ü­·¡C\n"NOR);
   set("wear_msg", "$N±N$n©Ü¤W¡A"HIY"ª÷Ãó©Ü­·"NOR"ªº¯«ªº¤O¶q³eª`¦b$N¨­¤¤¡A¨Ï$N«H¤ß­¿¼W¡C\n");
   set("unequip_msg", "$N±N$n°£¥h¡A"HIY"ª÷Ãó©Ü­·"NOR"ªº¤O¶qÀH¤§®ø³u¡C\n");
           set("armor_prop/armor",6);
   set("armor_prop/parry",3);
        }
        setup();
}
