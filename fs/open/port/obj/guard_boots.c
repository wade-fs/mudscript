inherit EQUIP;
void create()
{
	set_name("守衛隊戰靴",({"guard boots","boots"}));
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
由獸皮製成 , 對於移動有很大的幫助 , 可藉此瀰補
守衛隊戰鎧粗重的缺點 , 為楓林港守衛標準配備之一 !
");
        set("unit", "雙");
	set("value",800);
        set("material","cloth");
        set("armor_type", "boots");
        set("armor_prop/armor",2);
        set("armor_prop/dodge", 3);
        }
        setup();
}
