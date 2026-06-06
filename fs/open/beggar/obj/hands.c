#include <ansi.h>
#include <armor.h>
inherit HANDS;
void create()
{
        set_name(MAG + "雲  捃" + NOR,({"wind hands","hands"}));
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "雙");
        set("value",5000);
        set("long","丐幫古老相傳的護手套, 有相當的防禦力。\n");
        set("material","cloth");
        set("armor_prop/armor", 4);
        set("armor_prop/dodge",3);
        set("armor_prop/parry",2);
        set("armor_prop/move",1);
        }
        setup();
}

