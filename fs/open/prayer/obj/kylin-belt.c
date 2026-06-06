inherit EQUIP;

void create()
{
        set_name("麒麟腰帶",({"kylin belt","belt"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","抽取血麒麟的筋脈與其皮革混織而成的腰帶 , 可增強身體的防禦度 .\n");
        set("unit","條");
        set("value",50000);
        set("material","leather");
        set("armor_type","waist");
        set("armor_prop/armor", 5);
        }
        setup();
}                        
