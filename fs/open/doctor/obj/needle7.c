#include <ansi.h>
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("紫竹針",({"chu needle","needle"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "紫竹針乃取南海紫竹所製，具有療傷功\能！拿在手上不禁想到滿身罪惡怎配得上使用此針！\n");
                set("unit", "支");
                set("value",500);
                set("material", "steel");
                set("wield_msg", "$N伸手往針袋一掏，忽然一支$n掐在手指間！\n");
                set("unwield_msg", "$N將手中的$n插入針袋中。\n");
        }
init_stabber(70);
        setup();
}

