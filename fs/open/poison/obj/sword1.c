#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        seteuid(getuid());
        set_name(HIR "五極寒梅劍" NOR,({"five sword","sword"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","一把美麗的劍 ,劍柄上有著梅花的花紋 .\n");
                set("value",6000);
                set("material", "steel");
                set("ski_type","sword");
        set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        }
        init_sword(80);
        setup();
}

