#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
	set_name(""HIC"¹"HIW"p"HIC"¯"HIW"«"HIC"À"HIW"Y"HIC"²"HIW"¯"NOR"",({ "thunder_god_hat", "hat" }) );
	      	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "¤@³»¥i¥H´²±¼¹pÀ»®É¶Ë®`ªº´U¤l¡C\n");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
   set("no_get",1);
                set("no_put",1);
		set("unit", "³»");
                set_weight(3000);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 10);
                set("armor_prop/parry",7);
                set("armor_prop/force",5);
		// ­n´²¹p´N­n¾a³o­Ó°Õ, ´²¹p®ÄªG¦b 0-100, hehe
                set("thunder",100);
                set("wear_msg","$N±N$n©¹ÀY¤W¤@À¹¡AÀþ®É$n±µ¨ü¹p¯«ªº¯¬ºÖ¡A¨Ï¹pÀ»¤£´±¾aªñ¡C\n");
                set("remove_msg","$N±N$n²æ¤F¤U¨Ó¡A¯¬ºÖ¤]º¥º¥ªº®ø¥¢¤F¡C\n");

	}
        setup();
}
