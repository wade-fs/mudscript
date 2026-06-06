#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(HIB + "修羅戰鬥手套" + NOR,({"fiend hands","hands"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
冥殿修羅專用的手套, 能大量提高本身的攻擊力與雙手的肌力!!
");
        set("unit", "雙");
        set("value",10000);
        set("material","leather");
        set("armor_type", "hands");
        set("armor_prop/armor",5);
        set("armor_prop/attack",5);
        }
        setup();
}


