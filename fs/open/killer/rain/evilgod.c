inherit ITEM;
void create()
{
        set_name("天魔解體大法", ({ "evil_god" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
set("long","此乃天魔解體大法，上面寫著你看不懂的文字\n");
                set("value", 0);
        }
}
