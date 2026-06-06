//book.c

inherit ITEM;

void create()
{
	set_name("易經",({"book"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
	"一本以楷書寫成的易經，裡面記載著關於法術和養生之道的知識。\n");
		set("value",800);
		set("material", "paper");
		set("skill", ([
		"name":		"spells",
											// to learn this skill.
	"sen_cost":   10, // gin cost every time study
			"difficulty":	20,				// the base int to learn this skill
											// modify is gin_cost's (difficulty - int)*5%
	"max_skill": 40,
											// from this object.
		]) );
	}
        setup();
}
