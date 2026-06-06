// thunder_hat.c
#include <ansi.h>

inherit EQUIP;

void create()
{
    set_name(HIG + "綠帽" + NOR, ({ "green hat", "hat" }) );
	set_weight(2200);
	      	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一頂戴了會非常不爽的帽子。\n");
		set("unit", "頂");
		set("value",220);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 6);
		// 要散雷就要靠這個啦, 散雷效果在 0-100, hehe
        set("wear_msg", "$N戴綠帽了!!!!\n");
        set("thunder",100);
	}
        setup();
}
