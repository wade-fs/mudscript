// rose_flower.c

inherit COMBINED_ITEM;

void create()
{
	set_name("金線蟲",({"gold bug"}));
	set("unit","條");
	set("base_unit","條");
	set("base_weight", 1);
	set_amount(1);
	setup();
}
