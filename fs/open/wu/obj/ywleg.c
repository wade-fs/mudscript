#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
        set_name("金鏤戰膝",({"gold legging","legging"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW + "這是一件由傳說中玄天玉加上金鏤線所編成的護膝。\n" + NOR);
   set("wear_msg", "$N將$n穿上，" + HIY + "金鏤戰膝" + NOR + "的神奇力量使$N感覺即將飛翔。\n");
   set("unequip_msg", "$N將$n脫掉，" + HIY + "金鏤戰膝" + NOR + "的神奇力量從$N上逝去。\n");
        set("unit","件");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
        set("armor_prop/armor",20);
        set("armor_prop/move",3);
        }
        setup();
}
