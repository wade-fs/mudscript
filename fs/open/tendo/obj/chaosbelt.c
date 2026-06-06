// chaos-belt by Airke 
// QC by Anmy (98/2/25)

#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name( YEL + "混沌腰帶" + NOR  ,({"chaos belt","belt"}));
	set("long","繡工精細的土黃色腰帶，上面泛著日月形狀的螢光。\n");
	set_weight(600);
        set("armor_type","waist");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
		set("value",6000);
                set("material","cloth");
		set("armor_prop/armor",7);
                set("armor_prop/spells",5);
	set("armor_prop/force",8);
        }
        setup();
}
