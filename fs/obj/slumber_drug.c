// slumber_drug.c

inherit COMBINED_ITEM;

void create()
{
	set_name("蒙汗藥", ({ "slumber drug", "drug" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"這是尋常的綠林盜賊用來作案的蒙汗藥﹐你可以把它倒(pour)在\n"
			"酒水之中使用。\n" );
		set("unit", "包");
		set("base_value", 20);
		set("base_unit", "份");
		set("base_weight", 30);
	}
	set_amount(1);
	setup();
}

void init()
{
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("指令格式: pour <藥粉> in <物品>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("你身上沒有 " + what + " 這樣東西。\n");
	if( !ob->query("liquid_remaining") )
		return notify_fail(ob->name() + "裡什麼也沒有﹐先裝些水酒才能溶化藥粉。\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("drink_func", bind(f, ob));
	ob->add("slumber_drug", 100);
	message_vision("$N將一些" + name() + "倒進" + ob->name() 
		+ "﹐搖晃了幾下。\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("slumber_drug",
		(int)this_player()->query_condition("slumber_drug") 
		+ (int)ob->query("slumber_drug") );
	return 0;
}


