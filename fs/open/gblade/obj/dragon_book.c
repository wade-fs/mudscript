#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"狂龍刀譜"NOR,({"dragon-blade book","book"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","這是寫著狂龍刀法招式的一本書。\n");
                set("value",800);
                set("material", "paper");
        }
        setup();
}
