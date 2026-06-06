#include <ansi.h>
inherit EQUIP;

void create()
{
set_name("黑巾腰帶", ({"black belt", "belt"}) );
set_weight(200);
if ( clonep() )
set_default_object(__FILE__);
else{
set("long", "一條由特殊黑布織成的腰帶,相當奇特.\n");
set("material", "cloth");
set("unit", "條");
set("value", 100);
set("armor_type", "waist");
set("armor_prop/parry", 2);
set("armor_prop/dodge", 2);
set("armor_prop/armor", 3);
                setup();
}
}  
