//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
 set_name(CYN""BBLU"冥魔"HIR"甲冑"NOR,({"ghost-king-armor","armor"}));
 set_weight(100);
 if ( clonep() )
 set_default_object(__FILE__);
 else {
       set("long", CYN""BBLU"冥魔戰甲的一部份。\n"NOR);
       set("unit", "付");
       set("armor_type", "cloth");
       set("material", "leather");
       set("value", 500);
       set("armor_prop/armor", 10);
	   set("armor_prop/staff", 2);
	   set("armor_prop/blade",2 );
     }
       setup();
}






