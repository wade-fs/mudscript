inherit EQUIP;
void create()
{
	set_name("白虎之鎧",({"tiger armor","armor"}));
	set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
以上等精鋼鑲在白虎皮上 , 不但具有強大的防護能力
又彌補了厚重不便的缺點 , 為非常良好之鎧甲 .
");
        set("unit", "套");
	set("value",15000);
        set("material","steel");
	set("armor_type", "cloth");
	set("armor_prop/armor",20);
        }
        setup();
}
