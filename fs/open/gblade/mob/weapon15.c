#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("邪杖", ({ "evil staff","staff" }));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "
由邪氣凝聚成形的鋼杖，隱約間可感覺到邪靈嗜殺的呼喚。
\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N從腰際抽出$n握在手中.\n");
                set("unwield_msg", "$N將手中的$n插回腰際.\n");
        }
        init_staff(30);
        setup();
}
