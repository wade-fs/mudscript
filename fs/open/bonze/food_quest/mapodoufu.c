//mass.c
inherit ITEM;
 
void create()
{
        set_name("麻婆豆腐",({"mapo doufu" ,"mapo","doufu"}) );
        set_weight(195);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","哇！好大一盤的麻婆豆腐，豆腐、絞肉、蔥花…「嗯～」你還聞出裡面還有酒香，果真色香味俱全的一盤美味料理呢。");
                set("unit", "盤");
                set("value", 220);
                set("食物", ([
                        "剩" : 15, // 可以吃幾口
                        "供應": 135, // 每一口填飽肚子的量
                ]) );
        }
        setup();
}
