#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        seteuid(getuid());
        set_name("龍形三節棍",({"dragon-stick","stick"}));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
        set("long","這是一柄鋼製的三節棍，尾端部分則以黃甲金龍的骨頭製成龍形，藉以提高攻擊力．\n");

                set("value",30000);
                set("material", "steel");
        set("wield_msg", "$N從布包中抽出了$n，霎時間你覺得龍強大的力量灌入了雙臂。\n");
        set("unwield_msg", "$N將$n放進腰間的布包 。\n");
        }
        init_stick(90);
        setup();
}                            
