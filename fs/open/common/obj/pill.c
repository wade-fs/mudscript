
inherit F_MEDICINE;

void create()
{
        set_name("薏仁丹", ({"green pill","pill"}) );
	set("long",
"一粒薏仁丹,可用來補血,你可以吞下它(eat pill).\n"+
"(本朝中書省令: 為保障醫生生路,改善國民克藥習性,所有藥丸一律加上藥性.)\n");
	set("unit", "盒");
	set("base_unit", "粒");
        set("value", 300);
        set("base_weight", 100);
	set_amount(1);
	set("cure_type","heal");
	set("cure_heal_type","kee");
	set("medicine_power",30);
set("medicine_sick",115);
	setup();
}

