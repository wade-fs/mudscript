inherit ITEM;
void create()
{
        set_name("葉雙的人頭", ({ "yar_head" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 0);
        }
}
