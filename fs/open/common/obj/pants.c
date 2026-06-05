inherit EQUIP;

void create()
{
        set_name("高級西裝褲", ({ "wedding pants", "pants"  }) );
        set("unit", "件");
        set("long", "一件高級西裝褲，通常都是結婚的時候穿.\n");
	set("armor_type", "pants");
	set("armor_prop/armor", 7 );
	set("material", "布料");
	set_weight(2200);
	set("value",1800);
        setup();
}
