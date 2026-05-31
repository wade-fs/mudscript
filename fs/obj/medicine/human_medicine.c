inherit COMBINED_ITEM;
void create()
{
        set_name("人靈丹", ({"human pill","pill"}) );
        set("long",
        "此藥乃補氣之聖品,但須醫者精湛的醫術方可提煉.\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
        set("value",25000);
        set("base_weight", 50);
        set_amount(1);
        setup();
}
void init()
{
        if( this_player()==environment() )
        {
                add_action("eat_pill", "eat");
        }
}
int eat_pill(string arg)
{

        object ob,me=this_player();
        int max_kee,kee;
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
        message_vision("$N吃下一顆人靈丹，迅速提升自身體力.\n", me);
        max_kee = me->query("max_kee");
        kee = me->query("kee");
        kee = kee + 500;
        if( kee > max_kee )
            kee = max_kee;
        me->set("kee",kee);
        add_amount(-1);
        return 1;
}


