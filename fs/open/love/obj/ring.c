// Qc by Anmy 98/7/6
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
          set_name("疾電",({"power ring","ring"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
        set("long","這是一個指環，戴上後會有天神賜予閃電般的破壞力量。\n");
                set("value",1000);
                set("material", "crimsonsteel");
        }
        init_unarmed(40);
        setup();
}
