inherit EQUIP;

void create()
{
        set_name("白色新娘頭紗", ({ "white wedding lace", "lace"  }) );
        set("unit", "件");
        set("long", "一件白色新娘頭紗，通常都是結婚的時候穿.\n");
	set("gender_only", "女性");
	set("armor_type", "head");
	set("armor_prop/armor", 8 );
	set("material", "絲質");
	set_weight(500);
	set("value",500);
        setup();
}
