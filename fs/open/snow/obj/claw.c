// claw.c
#include <weapon.h>
inherit UNARMED;
void create()
{
        seteuid(getuid());
        set_name("鐵爪" ,({"claw"}));
        set_weight(1000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long","這是雪蒼弟子練習用之武器。\n");
        set("value",1000);
        set("material", "steel");
        }
        init_unarmed(10);
        setup();
}
