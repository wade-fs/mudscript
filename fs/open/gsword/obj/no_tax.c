inherit ITEM;

void create()
{
        set_name("免稅金牌", ({ "no_tax" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
set("long","朝庭所頒與可免稅的金牌.\n");
                set("value", 10000);
        }
}

