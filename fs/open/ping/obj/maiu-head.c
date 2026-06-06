inherit ITEM;

void create()
{
        set_name("苗王的人頭", ({ "maiu-head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
set("long","苗王的人頭,看來怪噁心的.\n");
                set("value", 0);
        }
}

