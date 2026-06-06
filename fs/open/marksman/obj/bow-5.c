#include <weapon.h>
#include <ansi.h>

inherit BOW;

void create()
{

set_name("霜雪弓",({"snow bow","bow"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long","一把經歷冰天雪地殘酷考驗,而打造出的弓。\n");
set("material","copper");
        }
        init_bow(25);
set("value",0);
        setup();
}
