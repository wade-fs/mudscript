#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name("金鏤頭帶", ({"gold helmet", "helmet"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long",HIW"這是一件由傳說中玄天玉加上金鏤線所編成的頭帶。\n"NOR);
   set("wear_msg", "$N將$n帶上，"HIY"金鏤頭帶"NOR"的力量使你心靈通明。\n");
   set("unequip_msg", "$N將$n拿下，"HIY"金鏤頭帶"NOR"的心中護持的力量隨之逝去。\n");
   set("armor_prop/armor",15);
   set("armor_prop/force",2);
        set("unit", "頂");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
