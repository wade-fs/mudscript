 inherit EQUIP;
void create()
{
        set_name("龍之護手",({"dragon hands","hands"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
龍皮製成的手套 , 能大量提高本身的破壞力
");
        set("unit", "雙");
        set("value",30000);
        set("material","cloth");
        set("armor_type", "hands");
        set("armor_prop/armor",3);
        set("armor_prop/attack",5);
        }
        setup();
}                    
