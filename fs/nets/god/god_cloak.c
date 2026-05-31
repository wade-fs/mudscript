//µI¤ÑÅ]¤ý cloak
#include <armor.h>
#include <ansi.h>
inherit EQUIP;


void create()
{
    set_name(""HIC"­"HIW"·"HIC"¯"HIW"«"HIC"©"HIW"Ü"HIC"­"HIW"·"NOR"",({"god cloak","cloak"}));
	set_weight(600);
        set("no_sell",1);
        set("no_auc",1);
set("no_drop",1);
   set("no_give",1);
   set("no_put",1);
   set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
Ä­²[­·¯«ªº¯¬ºÖ¡A¨Ï¦b¾Ô°«¤¤®Éªº²¾°Ê·|¦³ÂI¨³³t¡C
\n");
        set("unit", "¥ó");
        set("armor_type","cape");
        set("material","leather");
	set("armor_prop/armor",7);
	set("armor_prop/dodge",7);
        set("armor_prop/move",7);
set("wear_msg", HIW"$N©Ü¤W$n"HIW"¡A$N·P¨ü¨ì¨­Åé¥|©P¦³µÛ­·³òÂ¶µÛ\n"NOR);
set("remove_msg",HIW"$N±N$n"HIW"¨ø¤F¤U¨Ó¡A¥|©Pªº·L­·Âà²´ÀR¤î¤F¤U¨Ó¡C\n"NOR);

         }
        setup();
}
