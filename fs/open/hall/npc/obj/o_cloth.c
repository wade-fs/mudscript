#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("官制長袍", ({ "officer cloth", "cloth" }) );
        set_weight( 500);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "襲");
                set("long", "此長袍是官方公制的，看起來還滿好看的。\n");

        set("material", "cloth");
                set("value",  200);
                set("armor_prop/armor",  5);
        }
        setup();
}
