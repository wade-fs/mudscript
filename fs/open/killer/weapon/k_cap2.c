#include <ansi.h>
inherit EQUIP;

void create()
{
set_name("大紅彩帶",({"red cape","cape"}) );
set_weight(3000);
if ( clonep())
set_default_object(__FILE__);
else {
set("unit","條");
set("material","silk");
set("value", 320);
set("armor_type", "cape");
set("armor_prop/armor", 4);
set("armor_prop/dodge", 4);
set("long","
以東瀛運來之純黑絲織成的彩帶，在黑暗中移動，令人難以分清楚來人。\n");

}
setup();

}
