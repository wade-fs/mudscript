#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
	set_name("" + HIC + "" + HIW + "p" + HIC + "" + HIW + "" + HIC + "" + HIW + "Y" + HIC + "" + HIW + "" + NOR + "",({ "thunder_god_hat", "hat" }) );
	      	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "@iHp伅阨`UlC\n");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
   set("no_get",1);
                set("no_put",1);
		set("unit", "");
                set_weight(3000);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 10);
                set("armor_prop/parry",7);
                set("armor_prop/force",5);
		// npNnao荌, p蘆Gb 0-100, hehe
                set("thunder",100);
                set("wear_msg","$NN$nYW@A$np痋A牊paC\n");
                set("remove_msg","$NN$nFU荂A痐]FC\n");

	}
        setup();
}
