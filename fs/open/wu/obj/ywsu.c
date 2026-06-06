#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
        set_name("金鏤披風",({"gold surcoat","surcoat"}));
        set_weight(10000);
        set("armor_type","cape");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "件");
        set("material","leather");
        set("value",100000);
   set("long",HIW"這是一件由傳說中玄天玉加上金鏤線所編成的披風。\n"NOR);
   set("wear_msg", "$N將$n披上，"HIY"金鏤披風"NOR"的神的力量貫注在$N身中，使$N信心倍增。\n");
   set("unequip_msg", "$N將$n除去，"HIY"金鏤披風"NOR"的力量隨之消逝。\n");
   set("armor_prop/armor",20);
   set("armor_prop/parry",3);
        }
        setup();
}
