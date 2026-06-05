inherit ITEM;
 void create()
{
        set_name("火蜥蜴肉",({"lizard meat","meat"}) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","火蜥蜴的大腿肉, 肉質堅硬, 味道挺噁心的。 ");
                set("unit", "塊");
                set("value", 900000);
                set("食物", ([
                        "剩" : 250,
                        "供應": 90,
                ]) );
        }
        setup();
}
