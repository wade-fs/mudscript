// 金創藥 by onion
inherit F_MEDICINE;
void create()
{
	set_name("雪創膏", ({ "snow plaster","plaster" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("long","由京城藥店研發出來的治傷靈藥, 江湖人士均讚不絕口。\n");
	set("unit", "盒");
	set("base_unit", "盒");
	set("base_weight", 1000);
	set("value", 1500);
	set("cure_type","outheal");
	set("cure_heal_type","kee");
	set("medicine_power",50);
	set("medicine_times",13);
	}
        set_amount(1);
	setup();
}
