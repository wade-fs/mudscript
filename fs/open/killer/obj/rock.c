inherit ITEM;
void create()
{
        set_name("石頭", ({ "rock" }) );
        set_weight(6000);
        if( clonep() )
            set_default_object(__FILE__);
        else 
        {
            set("unit", "個");
        set("long","路邊的石頭，用來壓（put)東西剛好.\n");
        set("value", 1);
        }
}
