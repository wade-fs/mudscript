inherit EQUIP;
void create()
{
        set_name("忍者護手 ",({"nija armband","armband"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","此乃殺手的基本裝備，極為稀鬆平常的裝備");
        set("unit","個");
        set("value",6000);
        set("material","silver");
        set("armor_type","armbands");
        set("armor_prop/armor", 4);
        set("armor_prop/parry", 3);
        }
        setup();
}
