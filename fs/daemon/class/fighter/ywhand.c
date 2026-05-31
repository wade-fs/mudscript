inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("[1;31mª[1;33m÷[1;31mÃ[1;33mó[1;31mÅ[1;33m@[1;31m¤[1;33mâ[0m",({"gold hands","hands"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIW"³o¬O¤@¥ó¥Ñ¶Ç»¡¤¤¥È¤Ñ¥É¥[¤Wª÷Ãó½u©Ò½s¦¨ªº¤â®M¡C\n"NOR);
        set("wear_msg", "$N±N$nÀ¹¤W¡A"HIY"ª÷Ãó¤â®M"NOR"ªº¤O¶q±q¤â¤WÄ£²´¥ú¨~¡C\n");
        set("unequip_msg", "$N±N$n²æ±¼¡A"HIY"ª÷Ãó¤â®M"NOR"ªº¤O¶q±q¤â¤W³u¥h¡C\n");
        set("unit", "Âù");
        set("value",90000);
        set("material","cloth");
        set("armor_type", "hands");
        set("armor_prop/armor",12);
        set("armor_prop/unarme",2);
        set("armor_prop/attack",10);
        }
        setup();
}
