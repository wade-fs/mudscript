// 金創藥 by onion
inherit F_MEDICINE;
void create()
{
	set_name("金創藥", ({ "plaster" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
	set("long","治療外傷的尋常藥品, 可以敷在傷口上, 是行走江湖不可缺少的必備品。\n"+
		"\t用法 : apply plaster [at <target>]\n");
	set("unit", "盒");
	set("base_unit", "盒");
	set("base_weight", 1000);
	set("value", 800);
	set("cure_type","outheal");
	set("cure_heal_type","kee");
	set("medicine_power",20);
	set("medicine_times",8);
	}
	set_amount(1);
	setup();
}
