#include <armor.h>

inherit EQUIP;
void create()
{
set_name("永效型火摺子",({"fire torch","torch"}));
set("long","殺手在執行任務時，所用的長時間照明設備\n");
set_weight(500);
set("armor_type","finger");
set("light_up",-1);  
if( clonep() )
         set_default_object(__FILE__);
else {
                set("unit", "個");
set("value",3000);
set("material","gold");
set("armor_prop/armor",3);
set("light",-1);
        }
        setup();
}
