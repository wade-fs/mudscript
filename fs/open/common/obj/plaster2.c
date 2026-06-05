// 金創藥 by onion
inherit F_MEDICINE;
void create()
{
	set_name("天香斷續膏", ({ "spicy plaster","plaster" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("long","黝黑黑膏藥, 還有一股辛辣的味道, 但卻是西域一帶傳來最具療效的藥膏。\n");
	set("unit", "盒");
	set("base_unit", "盒");
	set("base_weight", 1000);
	set("value", 3000);
	set("cure_type","outheal");
	set("cure_heal_type","kee");
	set("medicine_power",70);
	set("medicine_times",16);
	}
        set_amount(1);
	setup();
}
