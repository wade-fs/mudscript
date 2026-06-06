inherit ITEM;
 
void create()
{
        set_name("熊掌",({"bear-palm","palm"}) );
        set_weight(240);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","據說是北極熊的熊掌，看起來頗為可口。 ");
                set("unit", "塊");
                set("value", 900);
                set("食物", ([
                        "剩" : 16,
                        "供應": 110,
                ]) );
        }
        setup();
}
