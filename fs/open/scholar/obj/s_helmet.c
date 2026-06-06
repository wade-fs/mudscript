// Qc by anmy (98/3/3)
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name("戰虎頭盔", ({"tiger_helmet", "helmet"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit", "頂");
	set("value", 10000);
	set("material", "steel");
        set("long","乃利用戰虎之血配合鍛鐵製成的頭盔。\n");
  	set("armor_prop/armor", 4);
// Swy QC 98/3/16
        set("armor_prop/dodge", 2);
        set("armor_prop/parry", 2);
        set("armor_prop/move", 1);
	set("thunder", 100);
}
	setup();
}
