#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
set_name(""HIR"ª"HIW"Ü"HIG"»"HIW"T"HIY"¬"HIW"X"HIB"¸"HIW"È"NOR"",({"angel_skirt","skirt"}));
set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
    set("long","³o¥ó¬X¸È¬O¥Ñ¤Ñ¤Wªº¥P¤k¦X¤O©ÒÂ´¦¨ªº , Ä­ÂÃµÛµL¤ñ¥P¬X¤§®ð\n");
               set("unit","¥ó");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
                set("no_put",1);
   set("no_get",1);
            set("material","fur");
                set("armor_prop/armor",15);
                set("armor_prop/dodge",7);
                set("armor_prop/move",7);
set("wear_msg","$N¬ï¤W$n¡A¬Ý°_¨Ó¯u¬O¥i·R·¥¤F .\n");
 }
        setup();
}
