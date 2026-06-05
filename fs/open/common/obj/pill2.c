// 藥丸

inherit F_MEDICINE;

void create()
{
	set_name("大還丹",({"large pill","pill"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","大還丹, 是藥店老闆採集一百零八種珍貴藥材, 費了七七四十九天煉製而成。\n");
		set("unit","盒");
		set("base_unit","粒");
        set("base_weight",100);
		set("value", 5000);
		set("cure_type","heal");
		set("cure_heal_type","kee");
		set("medicine_power",300);
set("medicine_sick",135);
	}
        set_amount(1);
	setup();
}
