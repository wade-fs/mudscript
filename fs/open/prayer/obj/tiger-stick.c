#include <weapon.h>
#include <weapon.h> 

inherit STICK;

void create()
{
        set_name( "虎牙雙節棍" , ({ "tiger stick","stick"}) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根鋼製的雙節棍，尾端則加上邪虎的虎牙，增強攻擊力。\n");
                set("value", 6000);
                set("material", "steel");
        }
        init_stick(30);

        set("wield_msg", "只見到$N大喝一聲，$n便從背後的布包裡飛躍而出。\n");
        set("unwield_msg", "$N向空中一拋，$n便自動飛回布包內。\n");

        setup();
}                   
