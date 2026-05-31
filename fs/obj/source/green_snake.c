// rose_flower.c

inherit COMBINED_ITEM;

void create()
{
	set_name("青花蛇",({"green snake"}));
	set("unit","條");
	set("base_unit","條");
	set("base_weight",50);
	set_amount(1);
	setup();
}
