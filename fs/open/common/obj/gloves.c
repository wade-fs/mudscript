inherit EQUIP;

void create()
{
        set_name("白色絲質手套", ({ "white silk gloves", "gloves"  }) );
        set("unit", "雙");
        set("long", "一雙白色絲質手套，通常都是結婚的時候穿.\n");
	set("armor_type", "hands");
	set("armor_prop/armor", 3 );
	set("material", "絲質");// 相當於 20, 對重量跟價值有用
	set_weight(500);
	set("value",200);
        setup();
}
