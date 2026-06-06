inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
        set_name("金鏤玉靴",({"gold boots","boots"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW + "這是一件由傳說中玄天玉加上金鏤線所編成的靴子。\n" + NOR);
   set("wear_msg", "$N將$n穿上，" + HIY + "金鏤玉靴" + NOR + "神的力量使$N腳上發出強大的光芒。\n");
   set("unequip_msg", "$N將$n脫掉，" + HIY + "金鏤玉靴" + NOR + "的力量隨之逝去。\n");
        set("unit", "雙");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
        set("armor_prop/armor",15);
        set("armor_prop/move",3);
        set("armor_prop/dodge", 3);
        }
        setup();
}
