//--by falcon
//2002-12-28修改 --by frequency & kalin 
#include <armor.h>
#include <ansi.h>
inherit CAPE;

void create()
{
    set_name(CYN""BBLU"冥魔"HIR"披風"NOR,({"ghost-king-cloak","cloak"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", CYN""BBLU"冥魔戰甲的一部份。\n"NOR);    
        set("unit", "件");
        set("value", 500);
        set("material", "leather");
		set("armor_type","cape");
		set("armor_prop/armor", 10);
        set("armor_prop/stabber", 2);
		set("armor_prop/sowrd", 2);
        }
        setup();
}


