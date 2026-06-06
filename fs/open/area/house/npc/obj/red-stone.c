 inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIR + "紅色石頭" + NOR,({"red stone","stone"}));
        set_weight(1000);
        if(clonep())
                set_default_object(__FILE__);
        else{
                set("base_unit","顆");
                set("value",1);
                set("long",@LONG
鮮紅色的石頭，彷彿鮮血一般的顏色，在最深紅的地方，似乎摻
雜著一種不可預支的深黑。
LONG);
        }
        setup();
}
