#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name("魔鞭",({ "daemon whip","whip"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
                set("value",10000);
                set("material","iron");
                set("wield_msg", "$N從懷中摸出一條$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n藏入懷中。\n");
        }
        init_whip(35);
        setup();
}                             
