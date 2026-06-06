 inherit EQUIP;
void create()
{
        set_name("乾坤護腕",({"boris hands","hands"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
聖火教教主專用的護腕, 能大量提高本身的攻擊力與雙手的肌力!!
");
        set("unit", "雙");
        set("value",100000);
        set("material","leather");
        set("armor_type", "hands");
        set("armor_prop/armor",5);
        set("armor_prop/attack",5);
        }
        setup();
}                    
