#include <ansi.h>
inherit EQUIP;


void create()
{
        set_name(HIB + "修羅戰鬥靴" + NOR,({"fiend boots","boots"}) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","冥殿修羅專用的戰鬥靴，以神獸金.木.水.火.土麒麟之甲精煉混織而成。\n");
        set("unit","雙");
        set("value", 50000);
        set("material","leather");
        set("armor_type","boots");
        set("wear_msg",HIC + "穿上$n之後，$N的身體頓時受到冥殿之氣的牽引，徐徐升起。\n" + NOR);
        set("armor_prop/move", 5);
        set("armor_prop/dodge", 5);
        set("armor_prop/armor", 5);
        }
        setup();
}


