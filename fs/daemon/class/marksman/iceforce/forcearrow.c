#include <weapon.h>
#include <ansi.h>

inherit ARROW;

void create()
{
set_name("雲氣箭",({"force arrow","force","arrow"}));
        set_weight(15);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","袋");
                set("base_unit","支");
                set("base_value",0);
                set("no_put",1);
                set("no_give",1);
                set("no_get",1);
                set("no_sell",1);
                set("no_auc",1);
                set("value",0);
                set("material", "wood");
             }
                init_arrow(100);
                set_amount(1);
                setup();
}
