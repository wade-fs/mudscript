inherit EQUIP;

void create()
{
        set_name("金剛臂環",({"emery armband","armband"}));

        set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","金剛砂與精剛混製而成的臂環, 上頭鑲嵌邪獸的眼珠, 藉以吸收外界中的邪氣, 引為己用 .\n");
        set("unit","只");
        set("value",10000);
        set("material","steel");
        set("armor_type","armbands");
        set("armor_prop/armor", 4);
        }
        setup();
}                        
