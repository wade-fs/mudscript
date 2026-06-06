inherit EQUIP;

void create()
{
        set_name("花衣服", ({ "color cloth", "cloth" }) );
        set_weight(1500);
        set("long", "一件花花亮亮的衣服，看起來似乎有點保護作用。\n");
        set("unit", "件");
        set("value",20);
        set("material", "cloth");
        set("armor_type", "cloth");
        set("armor_prop/armor", 10);
        setup();
}
