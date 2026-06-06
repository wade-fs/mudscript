inherit EQUIP;

void create()
{
        set_name("白色新娘曳地長裙", ({ "white wedding skirt", "skirt"  }) );
        set("unit", "件");
        set("long", "一件象徵純節高雅的白色新娘曳地長裙，通常都是結婚的時候穿.\n");
	set("armor_type", "pants");
	set("armor_prop/armor", 8 );
	set("material", "布料");
	set_weight(2000);
	set("value",3000);
        setup();
}
