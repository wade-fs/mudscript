//mass.c
inherit ITEM;
 
void create()
{
        set_name("蝦仁蛋炒飯",({"shrimp egg rice","shrimp","egg","rice"}) );
        set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","嘖！這麼大一盤的蝦仁蛋炒飯吃得完嗎？就算再好吃也讓人卻步，因為熱量比粽子多一倍！");
                set("unit", "盤");
                set("value", 300);
                set("食物", ([
                        "剩" : 15, // 可以吃幾口
                        "供應": 165, // 每一口填飽肚子的量
                ]) );
        }
        setup();
}
