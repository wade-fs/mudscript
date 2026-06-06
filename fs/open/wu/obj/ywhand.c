inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("金鏤護手",({"gold hands","hands"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIW"這是一件由傳說中玄天玉加上金鏤線所編成的手套。\n"NOR);
        set("wear_msg", "$N將$n戴上，"HIY"金鏤手套"NOR"的力量從手上耀眼光芒。\n");
        set("unequip_msg", "$N將$n脫掉，"HIY"金鏤手套"NOR"的力量從手上逝去。\n");
        set("unit", "雙");
        set("value",90000);
        set("material","cloth");
        set("armor_type", "hands");
        set("armor_prop/armor",15);
        set("armor_prop/unarme",2);
        set("armor_prop/attack",10);
        }
        setup();
}
