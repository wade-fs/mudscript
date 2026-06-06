//--by falcon
//2002-12-28修改 --by frequency & kalin 

#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
     set_name(CYN + "" + BBLU + "冥魔" + HIR + "邪盾" + NOR,({"ghost-king-shield","shield"}) );
     set_weight(200);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long",CYN + "" + BBLU + "冥魔戰甲的一部份。\n" + NOR);
            set("unit", "件");
            set("value",500);
            set("material","steal");
			set("armor_type", "shield");
            set("armor_prop/armor", 10);
			set("armor_prop/parry", 2);
           }
        setup();
}
