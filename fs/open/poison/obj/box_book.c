inherit ITEM;

void create()
{
	set_name("基本鞭法", ({"base whip book","whip book","book"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "本");
		set("value",100);
		set("material", "paper");
		set("skill", ([
			"name" : "whip",
			"exp_required": 1000,
			"sen_cost" : 35,
			"difficulty" : 15,
			"max_skill":  30,
		]) );
	set("long","這是一本基本鞭法，其上記載個種常鞭基本使法，及修練法。");
	}
	setup();
}
int valid_learn(object me)
{
 return 1;
}
