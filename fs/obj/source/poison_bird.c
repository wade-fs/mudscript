// rose_flower.c

inherit COMBINED_ITEM;

void create()
{
	set_name("千毒鳥的蛋",({"poison egg"}));
	set("unit","顆");
	set("base_unit","顆");
	set("base_weight",10);
	set_amount(1);
	setup();
}
