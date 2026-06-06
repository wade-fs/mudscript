#include <weapon.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name("血妖頸環", ({ "daemon amulet", "amulet" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 100000);
                set("material", "gem");
                set("armor_type","neck");
                set("armor_prop/armor", 15);
        }
        setup();
}
                        
