inherit EQUIP;

void create()
{
        set_name("高級絲質領帶", ({ "wedding scarf", "scarf"  }) );
        set("unit", "條");
        set("long", "一條高級紳士領帶，通常都是結婚的時候穿.\n");
	set("armor_type", "neck");
	set("armor_prop/armor", 3 );
	set("material", "絲料");
	set_weight(300);
	set("value",200);
        setup();
}
