#include <ansi.h>
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("竹針" ,({"chhu needle","needle"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
set("no_drop", 1);
set("no_sell", 1);
set("no_give", 1);
set("no_auc", 1);
set("long", "這竹針是由青竹所削製而成的!!為銀針門的信物\n");
                set("value",50);
                set("material", "iron");
                set("wield_msg", "$N伸手往針袋一掏，忽然一支$n掐在手指間！\n");
                set("unwield_msg", "$N將手中的$n插入針袋中。\n");
        }
        init_stabber(10);
        setup();
}


