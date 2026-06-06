
inherit EQUIP;

void create()
{
        set_name("紫翠長裙", ({ "blue skirt", "skirt" }) );
        set_weight(4500);
        set("long", "一件織工精細的紫色蟬絲長裙, 上面鑲著細細的金線, 顯得格外美麗。\n");
        set("unit", "件");
        set("value",5000);
        set("material", "絲質");
        set("armor_type", "pants");
        set("armor_prop/armor", 8);
        setup();
}
