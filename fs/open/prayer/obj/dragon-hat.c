inherit EQUIP;

void create()
{
        set_name("龍之頭帶", ({ "dragon_hat", "hat" }) );
        set_weight(3000);
                if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "黃甲金龍龍皮製成的頭部專用防護用具。\n");
                set("unit", "條");
                set("value",20000);
                set("material", "fur");
                set("armor_type", "head");
                set("armor_prop/armor", 7);
                
        }
        setup();
}                 
