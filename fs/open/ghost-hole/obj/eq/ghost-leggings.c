//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
        set_name(CYN + "" + BBLU + "冥魔" + HIR + "脛甲" + NOR,({"ghost-king-leggings","leggings"}));
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
              set("long",CYN + "" + BBLU + "冥魔戰甲的一部份。\n" + NOR);
              set("unit","雙");
              set("value",500);
              set("armor_prop/armor",5);
              set("armor_prop/dodge", 2);
			  set("armor_prop/move", 2);
              set("material","leather");
              set("armor_type","leggings");
            }
              setup();
}


