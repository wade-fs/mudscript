#include <weapon.h>

inherit STICK;

void create()
{
        set_name( "金剛三節棍" , ({ "emery stick","stick"}) );
        set_weight(13500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄玄鐵製的三節棍，棍中暗藏金剛砂，在攻擊時可以增加局部的傷害。\n");
                set("value", 10000);
                set("material", "blacksteel");
        }
        init_stick(60);

        set("wield_msg", "$N暗運內勁，$n感受到這股內勁後，錚錚作響。\n");
        set("unwield_msg", "$N內勁一收，$n的響聲才漸漸平息。\n");

        setup();
}                   
