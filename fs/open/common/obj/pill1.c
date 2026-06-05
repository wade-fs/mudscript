// 藥丸

inherit F_MEDICINE;

void create()
{
	set_name("小還丹",({"small pill","pill"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一顆小參丸,可用來活精補血,只要吃下(eat pill)它就可以了。\n");
		set("unit","盒");
		set("base_unit","粒");
		set("base_weight",300);
		set("value", 1500);
		set("cure_type","heal");
		set("cure_heal_type","kee");
		set("medicine_power",100);
set("medicine_sick",120);
	}
        set_amount(1);
	setup();
}
