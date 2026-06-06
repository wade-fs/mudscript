#include <weapon.h>
 
inherit STICK;
 
void create()
{
        set_name("齊眉棍", ({ "club" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "根");
               set("long", "這是一把看起相當普通的齊眉棍，看來是少林僧人練武專用的。\n");
               set("value", 400);
               set("material", "steel");
        }
        init_stick(25);
 
        set("wield_msg", "$N大喝一聲，把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n持在背後。\n");
 
 
        setup();
}
