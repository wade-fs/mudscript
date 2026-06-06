#include <ansi.h>

inherit EQUIP;

void create()
{
set_name("東瀛忍者服",({"nija cloth","cloth"}) );
set_weight(2000);
if( clonep() )
set_default_object(__FILE__);
else{
set("meterial","silk");
set("unit","件");
set("value", 10000);
set("armor_type","cloth");
set("armor_prop/armor", 13);
set("armor_prop/dodge", 7);
set("armor_prop/parry", 6);
set("long","這是東瀛忍者的專用服飾，工作專用非常特別。\n");
}
setup();
}
