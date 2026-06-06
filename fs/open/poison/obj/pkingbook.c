inherit ITEM;

void create()
{
	set_name("毒王心經", ({"poison book","book"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "本");
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name":   "poison",
			"exp_required":1500,
			"sen_cost":   30,
			"difficulty":  25,
			"max_skill":  40,
		]) );
		set("long", "這是一本記載著用毒招式和心法的奇書，相傳是數十年
前一使毒奇人，千手毒王窮盡其畢生心血所著。\n");
	}
	setup();
}

int valid_study(object me)
{
	if(me->query("family/family_name")!="冥蠱魔教")
	return notify_fail("你看不懂此書.\n");
	return 1;
}
