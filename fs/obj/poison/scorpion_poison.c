// dust.c

inherit COMBINED_ITEM;

void create()
{
	set_name("蠍毒",({"scorpion poison","scorpion","poison"}));
	set("unit", "包");
	set("base_unit", "份");
	set("base_weight", 1);
	set("can_throw",1);
	set("poison_type","scorpion_poison");
 set("poison_power",3);
        set("poison" , 30);
	set_amount(1);
	setup();
}
