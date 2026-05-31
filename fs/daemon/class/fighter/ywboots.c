inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("[1;31mª[1;33m÷[1;31mÃ[1;33mó[1;31m¥[1;33mÉ[1;31m¹[1;33mu[0m",({"gold boots","boots"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"³o¬O¤@¥ó¥Ñ¶Ç»¡¤¤¥È¤Ñ¥É¥[¤Wª÷Ãó½u©Ò½s¦¨ªº¹u¤l¡C\n"NOR);
   set("wear_msg", "$N±N$n¬ï¤W¡A"HIY"ª÷Ãó¥É¹u"NOR"¯«ªº¤O¶q¨Ï$N¸}¤Wµo¥X±j¤jªº¥ú¨~¡C\n");
   set("unequip_msg", "$N±N$n²æ±¼¡A"HIY"ª÷Ãó¥É¹u"NOR"ªº¤O¶qÀH¤§³u¥h¡C\n");
        set("unit", "Âù");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
          set("armor_prop/armor",6);
        set("armor_prop/move",3);
        set("armor_prop/dodge", 3);
        }
        setup();
}
