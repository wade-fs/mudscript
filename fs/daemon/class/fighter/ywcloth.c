#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
   set_name("[1;31mª[1;33m÷[1;31mÃ[1;33mó[1;31m¥[1;33mÉ[1;31m¦[1;33mç[0m" ,({"gold cloth","cloth"}));
   set_weight(30000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
   set("unit","¥ó");
   set("value",150000);
   set("material", "cloth");
   set("long",HIW"³o¬O¤@¥ó¥Ñ¶Ç»¡¤¤¥È¤Ñ¥É¥[¤Wª÷Ãó½u©Ò½s¦¨ªºÄ_¦ç¡C\n"NOR);
   set("wear_msg", "$N±N$n¬ï¤W¡A"HIY"ª÷Ãó¦ç"NOR"ªº¤O¶q³eª`¦b$N¨­¤¤¡C\n");
   set("unequip_msg", "$N±N$n²æ±¼¡A"HIY"ª÷Ãó¦ç"NOR"ªº¤O¶qÀH¤§³u¥h¡C\n");
set("armor_prop/armor",22);
   set("armor_prop/force",3);
   set("armor_prop/unarme",3);
   set("armor_prop/dodge",-5);
}
        setup();
}
