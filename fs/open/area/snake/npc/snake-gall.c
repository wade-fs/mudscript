inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG + "蛇膽" + NOR,({"snake gall","gall"}));
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else{
                set("base_unit","個");
                set("unit","把");
                set("value",1000);
                set("long",@LONG
青綠色的蛇膽，看起來十分噁心，其中心由深綠轉黑，更有一種
莫名的神秘感．
LONG);
        }
        setup();
}
