
#include <weapon.h>
#include <ansi.h>
inherit LANCE;
void create()
{
        seteuid(getuid());
set_name("蛇戟",({"snake lance","lance"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
    set("long","這支槍尖有點像蛇一樣的扭曲.\n");
                set("value",5500);
                set("material", "steel");
        set("wield_msg", "$N裝備起來覺的手感感覺的特好的。\n");
         }
        init_lance(25);
        setup();
}

