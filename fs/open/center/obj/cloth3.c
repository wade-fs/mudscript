inherit EQUIP;

void create()
{
        set_name("紫翠衣服", ({ "blue cloth", "cloth" }) );
        set_weight(5500);
        set("long", "一件織工精細的紫色蟬絲質衣服, 上面鑲著烏金, 可見它的名貴。\n");
        set("unit", "件");
        set("value",5000);
        set("material", "絲質");
        set("armor_type", "cloth");
        set("armor_prop/armor", 13);
        setup();
}
