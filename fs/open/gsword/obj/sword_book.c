// blade_book.c

inherit ITEM;

void create()
{
	set_name("基礎劍譜", ({ "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"這是一本簡單的劍譜,隨便一個武館都找的到.\n"
			"然而若你想學劍,這到是適合初學者的好書.\n");
		set("value", 10);
		set("material", "paper");
		set("skill", ([
			"name": 		"sword",		// name of the skill
                        "exp_required": 500,
											// to learn this skill.
                        "sen_cost":             30,
                        "difficulty":   30,
											// modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    30,
											// from this object.
		]) );
	}
        setup();
}
