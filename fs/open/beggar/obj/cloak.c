#include <ansi.h>
#include <armor.h>
inherit CAPE;
void create()
{
        set_name("乞丐斗篷",({"beggar cloak","cloak"}));
        set_weight(2200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
        set("value",5000);
        set("material","leather");
        set("long","乞丐們用的斗篷。\n");
        set("armor_prop/armor",8);
        set("armor_prop/dodge",2);
        }
        setup();
}
