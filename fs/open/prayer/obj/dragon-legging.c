inherit EQUIP;

void create()
{
        set_name("龍甲護膝",({"dragon legging","legging"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","用火龍鱗甲製成的護膝 , 能增強雙腳的防禦度 .\n");
        set("unit","件");
        set("value",30000);
        set("material","leather");
        set("armor_type","leggings");
        set("armor_prop/armor", 3);
        set("armor_prop/move",-1);
        }
        setup();
}                        
