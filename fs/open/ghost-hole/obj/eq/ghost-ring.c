//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <ansi.h>
#include <armor.h>
inherit EQUIP;
object user;
int kar;
void create()
{
     set_name(CYN + "" + BBLU + "冥魔" + HIR + "指戒" + NOR,({"ghost-king-ring","ring"}) );
     set_weight(25);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long",CYN + "" + BBLU + "冥魔戰甲的一部份\n" + NOR);
            set("unit", "件");
            set("value",500);
            set("material","steal");
			set("light_up",-1);
            set("armor_type","finger");
            set("armor_prop/magic",2);
			set("armor_prop/force",2);
			set("armor_prop/spells",2);
           }
        setup();
}
