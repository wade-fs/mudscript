//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <ansi.h>
#include <armor.h>

inherit EQUIP;

void create()
{
    set_name(CYN + "" + BBLU + "冥魔" + HIR + "肩甲" + NOR,({"ghost-king-armband","armband"}));
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
        set("long",CYN + "" + BBLU + "冥魔戰甲的部份。\n" + NOR);
        set("unit", "副");
        set("value", 500);
        set("material", "blacksteel");
        set("armor_prop/armor", 5);
        set("armor_prop/unarmed",2);
        set("armor_prop/arrow", 10);
		 set("armor_prop/dagger", 2);

        set("armor_type","armbands");
       }
        setup();
}



