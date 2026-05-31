#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
        set_name("[1;31mª[1;33m÷[1;31mÃ[1;33mó[1;31m¾[1;33mÔ[1;31m½[1;33m¥[0m",({"gold legging","legging"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"³o¬O¤@¥ó¥Ñ¶Ç»¡¤¤¥È¤Ñ¥É¥[¤Wª÷Ãó½u©Ò½s¦¨ªºÅ@½¥¡C\n"NOR);
   set("wear_msg", "$N±N$n¬ï¤W¡A"HIY"ª÷Ãó¾Ô½¥"NOR"ªº¯«©_¤O¶q¨Ï$N·PÄ±§Y±N­¸µ¾¡C\n");
   set("unequip_msg", "$N±N$n²æ±¼¡A"HIY"ª÷Ãó¾Ô½¥"NOR"ªº¯«©_¤O¶q±q$N¤W³u¥h¡C\n");
        set("unit","¥ó");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
      set("armor_prop/armor",6);
        set("armor_prop/move",3);
        }
        setup();
}
