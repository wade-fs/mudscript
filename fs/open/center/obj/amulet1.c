inherit EQUIP;

void create()
{
        set_name("翡翠項鍊", ({ "amulet" }) );
        set_weight(500);
        set("long", "一條有上等翡翠項鍊" );
        set("unit", "條");
        set("value",2000);
        set("material", "翡翠");
        set("armor_type", "amulet");
        set("armor_prop/arm", 3);
        setup();
}
