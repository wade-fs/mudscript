#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
set_name(""HIY"¥"HIW"ú"HIY"¤"HIW"§"HIY"Å"HIW"@"HIY"¤"HIW"â"NOR"",({"light_gloves","gloves"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
                 "¥~­±¬Ý°_¨ÓÁöµM²@¤£°_²´ , ¦ý¬O·í§AÀ¹¤W¥L®É\n"
                 "´N·|µo½÷¥XµL»P­Û¤ñªº«Â¤O ¡C\n");
                set("unit","¥ó");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
   set("no_get",1);
                set("no_put",1);
                set("material","leather");
                set("armor_prop/armor",15);
                set("armor_prop/parry",10);
                set("armor_prop/force",5);
set("wear_msg","¥|©P¥ú¨~©¿µM»E¶°¨ì$NªºÂù¤â¡A$n¤w¦b§A¤â¤W§Î¦¨¤@¹D«OÅ@¡C\n");
 }
        setup();
}
