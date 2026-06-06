inherit EQUIP;

void create()
{
        set_name("金剛腰帶",({"emery belt","belt"}));
        set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","金剛砂與皮革混製而成的腰帶, 可以增強腰部的防禦力.\n");
        set("unit","條");
        set("value",10000);
        set("material","steel");
        set("armor_type","waist");
        set("armor_prop/armor", 2);
        }
        setup();
}                        
