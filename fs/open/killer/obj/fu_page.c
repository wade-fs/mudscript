inherit ITEM;
void create()
{
        set_name("鳳姑的香包", ({ "fu_page" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 0);
        }
}
