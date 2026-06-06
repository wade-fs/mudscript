inherit EQUIP;

void create()
{
        set_name("風之短統靴",({"wind boots","boots"}) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","西域特製的靴子，以西域特製的布料與皮革混織而成。\n");
        set("unit","雙");
        set("value", 1500);
        set("material","leather");
        set("armor_type","boots");
        set("armor_prop/armor", 1);
        }
        setup();
}        
