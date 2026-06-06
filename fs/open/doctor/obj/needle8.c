// ice-needle.c
#include <ansi.h>
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name(HIW + "冰蠶寒絲針" + NOR,({"ice needle","needle"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "冰蠶寒絲針乃棌天山冰蠶所吐絲而編織，其絲強韌，冰冷，需有深厚的內力方可持有！\n");
                set("value",50000);
                set("rigidity", 30);
                set("material", "crimsonsteel");
                set("wield_msg", "$N伸手往針袋一掏，忽然一支$n掐在手指間！\n");
                set("unwield_msg", "$N將手中的$n插入針袋中。\n");
        }
        init_stabber(80);
        setup();
}


