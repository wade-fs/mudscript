#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
set_name( ""HIY"¤"HIW"Û"HIR"¤"HIW"ë"HIR"¥"HIW"É"HIY"Å"HIW"N"NOR"",({"moon_bracelet","bracelet"}));
set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","³o¥óÄ_ª«¥­±`³£¬O¥Ñ¤ë¯«©Ò´xºÞµÛ , ¥u¦³©M¥¦¾Ö¦³¬Û¦PÆF©Êªº¤H¤~¯à¬ïÀ¹\n");
                set("unit", "­Ó");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
                set("no_put",1);
   set("no_get",1);
         set("material","gem");
                set("armor_prop/armor",15);
                set("armor_prop/parry",10);
                set("armor_prop/force",9);
set("wear_msg","$N®M¤W$n¡A¨ü¨ì¤ë«G¤§¯«ªº¯¬ºÖ¡A«H¤ß¤j¼W .\n");
 }
        setup();
}
