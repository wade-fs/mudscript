inherit EQUIP;

void create()
{
        set_name("堅頭曼皮鞋", ({ "gentleman boots", "boots"  }) );
        set("unit", "雙");
        set("long", "一雙紳士皮鞋，通常都是結婚的時候穿.\n");
	set("armor_type", "boots");
	set("armor_prop/armor", 3 );
	set("material", "皮革");// 相當於 20, 對重量跟價值有用
	set_weight(1200);
	set("value",1800);
        setup();
}
