// thousand.c

inherit MONEY;

void create()
{
    set_name("萬兩銀票", ({"cash", "cash_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("money_id", "cash");
        set("long", "一張面額值一萬兩銀子的銀票。\n");
		set("unit", "疊");
        set("base_value", 1000000);
		set("base_unit", "張");
		set("base_weight", 3);
	}
	set_amount(1);
	setup();
}
