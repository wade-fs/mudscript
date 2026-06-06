// gold-hat by roger
//報酬eq

#include <armor.h>
#include <ansi.h>

inherit HEAD;
void create()
{
	set_name(HIY + "金翅朝天冠" + NOR, ({"gold hat", "hat"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long", "一頂旁邊延伸出一對金翅的黃金冠冕。\n");
	set("unit", "頂");
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
	set("value", 300000);
	set("material", "gold");
	set("armor_prop/armor", 12);
        set("armor_prop/dodge",4);
        set("armor_prop/move",4);
	}
	setup();
}
int query_autoload()
{
 return 1;
}

