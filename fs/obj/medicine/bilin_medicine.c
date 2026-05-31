inherit COMBINED_ITEM;
void create()
{
        set_name("碧靈丹", ({"bie pill","pill"}) );
        set("long",
        "此物乃蜀中將軍自天山絕頂採來之神藥,可以恢復大量內力.\n"+
        "此要須經藥師調配(check item),方得食用(eat pill).\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
        set("value",2500);
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
        int heal;
        object ob,me=this_player();
        heal = this_player()->query("max_kee")/10;
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
        message_vision("$N吃下一粒碧靈丹.\n", me);
        me->receive_curing("kee", heal );
        add_amount(-1);
        return 1;
}

