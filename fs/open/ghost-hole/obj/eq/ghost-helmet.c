//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
void create()
{
    set_name(CYN + "" + BBLU + "冥魔" + HIR + "帝冠" + NOR,({"ghost-king-helmet","helmet"}));
    set("long",CYN + "" + BBLU + "冥魔戰甲的一部份" + NOR);   
    set_weight(25);
        set("armor_type","head");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "頂");
                set("value", 500);
                set("material","steel");
                set("armor_prop/armor", 5);
                set("armor_prop/cure" ,2);
				set("armor_prop/plan" ,2);
				set("armor_type","head");
                set("thunder", 1000000000000);
       }
        setup();
}
