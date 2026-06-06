//diaper.c by chun

inherit ITEM;

void create()
{
	set_name("強褓",({"diaper"}));
	set("long","提供嬰兒最基本保護的布。\n");
	set_weight(10);
	set("unit","塊");
        set("value",10);
        setup();
}
