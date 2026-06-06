#include <ansi.h>
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("雪鯉銀針",({"li needle","needle"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "雪鯉銀針是從天山冰河中的雪鯉身上的鱗片所鍊制。/n");
                set("unit", "支");
                set("value",1000);
                set("rigidity", 30);
                set("material", "ironsteel");
                set("wield_msg", "$N伸手往針袋一掏，忽然一支$n掐在手指間！\n");
                set("unwield_msg", "$N將手中的$n插入針袋中。\n");
        }
        init_stabber(50);
        setup();
}


