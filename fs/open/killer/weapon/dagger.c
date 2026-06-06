#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC "滅神匕首" NOR,({"god dagger","dagger"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是葉秀殺與莊靜柔與柴榮三人之間的信物，\n
當年的事件之後，這把匕首就不知去向，如今居然出現在你的手上。\n");
                set("value",50000);
                set("material", "steel");
        }
        init_dagger(70);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

// The setup() is required.
        setup();
}
