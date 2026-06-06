// 基礎刺術

inherit ITEM;

void create()
{
	set_name("基礎刺術集", ({ "stabber_book","book" }));
	set_weight(900);
	if( clonep() )
	  set_default_object(__FILE__);
	else 
	{
	  set("unit", "本");
	  set("long","這是一本講述基本刺術的書籍, 作者署名「楊書文」。\n");
          set("value", 300);
	  set("material", "paper");
	  set("skill", ([
	  "name" : "stabber",		// name of the skill
          "exp_required" :  100,
				        // to learn this skill.
          "sen_cost" : 22,              // gin cost every time study this
          "difficulty" : 20,
					// modify is gin_cost's (difficulty - int)*5%
          "max_skill":  30
	  ]) );
	}
}

