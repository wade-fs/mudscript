#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        seteuid(getuid());
        set_name("鬼頭刀",({"ghost-head blade","blade"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是一種江湖豪客常用的刀 ,看起來頗為沉重 .\n");
                set("value",10000);
                set("material", "gold");
                set("wield_msg", "拿著$n,$N覺得渾身充滿了殺氣.\n");
                set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
        }
        init_blade(40);

        setup();
}

