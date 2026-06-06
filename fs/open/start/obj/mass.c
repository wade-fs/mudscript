 
inherit ITEM;
 
void create()
{
        set_name("璐璐翡翠粽", ({ "little mass" , "mass" }) );
        set_weight( 90 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "小小的一顆菜粽, 通體碧綠, 裡面包的是蘆筍, 蓮子, 菱角等爽口的材料, 在炎炎夏日中為您帶來一陣清涼。\n");
                set("unit", "粒");
                set("value", 75);
                set("食物", ([
                        "剩" : 5,
                        "供應": 45,
                ]) );
        }
        setup();
}
