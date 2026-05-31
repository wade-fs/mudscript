// rose_flower.c

inherit COMBINED_ITEM;

void create()
{
	set_name("花煙草",({"smell"}));
	set("unit","枝");
	set("base_unit","枝");
	set("base_weight", 1);
	set_amount(1);
	setup();
}
