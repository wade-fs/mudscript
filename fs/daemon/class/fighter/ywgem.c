#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
    set_name("[1;31mª[1;33m÷[1;31mÃ[1;33mó[1;31m¬[1;33mP[1;31m½[1;33m÷[0m", ({"gold neck","neck"}) );
     set_weight(5000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
   set("long",HIW"³o¬O¤@¥ó¥Ñ¶Ç»¡¤¤¥È¤Ñ¥ÉÆ^¤W¬P½÷¥Û¦ê¤Wª÷Ãó½uªº¶µÁå¡C\n"NOR);
   set("wear_msg", "$N±N$nÀ¹¤W¡A¨­¤Wµo¥X"HIW"¬P½÷"NOR"¯ëªº¥ú¨~¡C\n");
   set("unequip_msg", "$N±N$n²æ±¼¡A¨­¤Wªº¥ú¨~ÀH¤§³u¥h¡C\n");
      set("armor_prop/armor",7);
   set("armor_prop/dodge",3);
            set("unit", "±ø");
            set("armor_type", "neck");
            set("value", 30000);
     }
}

