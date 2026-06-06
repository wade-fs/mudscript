inherit ITEM;

void create()
{
        set_name("苗人信物", ({ "maiu_id" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
set("long","持此信物,便可參見苗王.\n");
                set("value", 0);
        }
}

