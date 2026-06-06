// Qc by anmy (98/3/3)
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(RED + "竣龍馴之顎" + NOR, ({"dragon helmet", "helmet","dragon"}));
        set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit", "頂");
        set("value", 31000);
        set("material", "steel");
        set("long","相傳洪七公以雷龍顎所作成的帽子, 有相當強大的效用。\n");
        set("armor_prop/armor", 12);
        set("armor_prop/dodge", 7);
        set("armor_prop/pary", 5);
        set("armor_prop/staff", 8);
        set("thunder", 100);
}
	setup();
}
