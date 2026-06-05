// 金創藥 by onion
inherit F_MEDICINE;
void create()
{
	set_name("曼羅聖心膏", ({ "heart plaster","plaster" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("long","江湖上不傳的秘方，芳香的味道令人神清氣爽，卻是最好的療傷聖品。\n");
	set("unit", "盒");
	set("base_unit", "盒");
	set("base_weight", 1000);
	set("value", 10000);
	set("cure_type","outheal");
	set("cure_heal_type","kee");
	set("medicine_power",125);
	set("medicine_times",30);
	}
	set_amount(1);
	setup();
}
