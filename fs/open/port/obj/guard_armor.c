inherit EQUIP;
void create()
{
	set_name("守衛隊戰鎧",({"guard armor","armor"}) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
以一片片小鋼片串接而成 , 穿在身上 , 甚具防護功效 , 
卻因此而引響了活動力 , 是楓林港守衛特有的防具 .
");
        set("unit", "套");
	set("value",1500);
        set("material","steel");
	set("armor_type","cloth");
        set("armor_prop/armor",10);
        set("armor_prop/dodge", -1);
        }
        setup();
}
