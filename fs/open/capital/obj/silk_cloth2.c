inherit EQUIP;

void create()
{
	set_name("錦衣", ({ "silk cloth", "cloth" }) );
        set_weight(3500);
	set("long", "一件繡工精細的絲質衣服, 一看就知道是富貴人家才穿得起的衣裳 \n");
        set("unit", "件");
	set("value",1000);
        set("material", "絲質");
        set("armor_type", "cloth");
	set("armor_prop/armor", 5);
        setup();
}
