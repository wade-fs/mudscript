
//攜帶mob exp180萬;kee 5000;dragon-blade 120;比master還強
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        seteuid(getuid());
        set_name(HIR + "日月神刀" + NOR,({"sun-moon blade","blade","sun-moon"}));
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","吸收了四日光與月光精華的刀。\n");
                set("value",100000);
                set("material", "crimsonsteel");
                set("wield_msg", HIR + "拿著$n,$N的身體突然充滿力量\n" + NOR);
                set("unwield_msg", HIB + "$N放下$n,身上的力量也消失了。\n" + NOR);
        
}
    init_blade(70);
        setup();
}

