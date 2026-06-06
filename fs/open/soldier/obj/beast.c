
#include <weapon.h>
#include <ansi.h>
inherit LANCE;
void create()
{
        seteuid(getuid());
set_name("獸矛",({"beast lance","lance"}));
        set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
    set("long","一把專門用來獵取獵物的槍,在槍底端還有一尖錐.\n");
                set("value",5000);
                set("material", "copper");
        set("wield_msg", "$N從背後抽出$n,全身充滿了獸力。\n");
        set("unwield_msg", "$N將手中$n放回背上。\n");
      }
        init_lance(30);
        setup();
}

