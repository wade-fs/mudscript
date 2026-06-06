#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
    set_name("鼠刈",({"mouse bite","mouse","bite"}));
    set_weight(300);
  if( clonep() )
                set_default_object(__FILE__);
        else {
    set("unit", "隻");
    set("base_unit","隻");
    set("base_value",700);
    set("value",700);
    set("material", "steel");
   }
    init_throwing(90);
    set_amount(2);
    setup();
}
