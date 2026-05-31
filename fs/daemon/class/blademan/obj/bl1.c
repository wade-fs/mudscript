
#include <weapon.h>

inherit BLADE;

void create()
{
       set_name("壇木刀",({"blade"}));
         set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "
  一把由壇香木所造成的刀,適何同門拆招用...\n");
                set("value", 500);
                 set("material", "wood");
         set("wield_msg", "一陣檀香味傳了出來,$N拿出一把檀木刀。\n");
               set("unwield_msg", "$N將手中的$n收了回去。 \n");
        }
     init_blade(10);
        setup();
}

