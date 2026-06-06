#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIG + "青蛇頭盔" + NOR, ({"snake helmet", "helmet"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "頂");
        set("value", 100000);
        set("material", "steel");
        set("long","
這頂頭盔上頭有標示著一隻蛇，雖然不曉得有什麼意義，不過
卻是一個不錯的頭盔。\n");
        set("armor_prop/armor", 10);
	set("armor_prop/force",3);
        }
        setup();
}
