// apron.c

inherit EQUIP;

void create()
{
	set_name("圍裙", ({ "Apron", "apron" }) );
	set_weight(1000);
	set("gender_only", "女性");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一條家庭主婦穿著的圍裙。\n");
		set("unit", "條");
		set("value", 250);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/dodge", 1);
	}
        setup();
}
