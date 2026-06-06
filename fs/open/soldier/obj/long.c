
#include <weapon.h>
#include <ansi.h>
inherit LANCE;
void create()
{
        seteuid(getuid());
set_name("長槍",({"long lance","lance"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
    set("long","這把槍身和槍間都是用鐵所打鑄的,尤其他的槍身比木槍長一點.\n");
                set("value",3000);
                set("material", "iron");
 }
        init_lance(20);
        setup();
}

