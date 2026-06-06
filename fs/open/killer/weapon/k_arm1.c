inherit EQUIP;
void create()
{
        set_name("黑巾護手 ",({"black armband","armband"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","此乃殺手的基本裝備，極為稀鬆平常的裝備");
        set("unit","個");
        set("value",1750);
        set("material","silver");
        set("armor_type","armbands");
        set("armor_prop/armor", 2);
        set("armor_prop/parry", 2);
        }
        setup();
}
