inherit EQUIP;

void create()
{
	set_name("精金戰鎧",({"gold armor","armor"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
由精鋼混合黃金打造而成 , 防護頗佳 ,但甚為沉重。
");
        set("unit", "套");
	set("value",4000);
        set("material","crimsonsteel");
	set("armor_type", "cloth");
	set("armor_prop/armor",20);
	set("armor_prop/dodge", -2);
	set("armor_prop/move",-2);
        }
        setup();
}
