//既然此物是杖 就用杖的敘述吧XD 更正之 by blazakira 2010/12/12
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
     set_name("未開光的杖", ({ "poor staff","staff" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把稀世珍寶之杖，樸實無華的模樣似乎尚未開光。\n");
                set("value", 50);
        set("material","wood");
        }
        init_staff(20);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N「唰」地一聲抽出一隻$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n隨手插在腰間。\n");

// The setup() is required.

        setup();
}

