inherit ITEM;
void create()
{
        set_name("傷寒雜病論", ({ "cure book","book" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "這是一本有關醫術和藥物的書籍，.\n"
                        "如果你想學醫，這本書倒挺適合。.\n");
                set("value", 10);
                set("material", "paper");
                set("skill", ([
                "name":   "cure",       // name of the skill
                        "exp_required": 500,

 // to learn this skill.
                        "sen_cost":             30,

                        "difficulty":   30,

 // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    26,

 // from this object.
                ]) );
        }
        setup();
}


