// rain_cloth.c

inherit EQUIP;

void create()
{
	set_name("輕便型雨衣", ({ "rain cloth", "cloth" }) );
	set_weight(1200);
	      	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件透氣舒適的雨衣，很適合雨天時穿著。\n");
		set("unit", "件");
		set("value",30);
		set("material", "毛皮");
		set("armor_type", "cloth");
		set("rain_cover",100);
		set("armor_prop/armor", 4);
	}
        setup();
}
