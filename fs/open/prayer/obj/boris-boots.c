inherit EQUIP;

void create()
{
        set_name("乾坤戰鬥靴",({"boris boots","boots"}) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","聖火教教主專用的戰鬥靴，以怪獸鱗甲精煉混織而成。\n");
        set("unit","雙");
        set("value", 50000);
        set("material","leather");
        set("armor_type","boots");
        set("wear_msg","穿上$n之後，$N的身體頓時受到九天之氣的牽引，徐徐升起。\n");
        set("armor_prop/move", 5);
        set("armor_prop/dodge", 5);
        set("armor_prop/armor", 5);
        }
        setup();
}        
