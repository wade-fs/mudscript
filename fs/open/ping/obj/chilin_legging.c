inherit EQUIP;
#include <ansi.h>
void create()
{
        set_name(HIB + "麒麟甲" + NOR,({"chilin legging","legging"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","傳說中古代麒麟身上護甲所製成，具強大的防禦力。\n");
        set("unit","件");
        set("value",2000);
        set("material","cloth");
        set("armor_type","leggings");
        set("armor_prop/armor", 5);
        set("armor_prop/attack",4);
        set("armor_prop/parry",4);
        set("armor_prop/unarmed",3);
        }
        setup();
}

