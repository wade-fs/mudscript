 
inherit ITEM;
 
void create()
{
        set_name("小拉大龍棕",({"pyramid mass","mass"}) );
        set_weight(180);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","哇！好大的一個粽子，足足有一斤重，裡面包滿了蛋黃香菇，鮮蝦蓮蓉，真是滋補聖品，令人吃了還想再吃。 ");
                set("unit", "粒");
                set("value", 150);
                set("食物", ([
                        "剩" : 10,
                        "供應": 90,
                ]) );
        }
        setup();
}
