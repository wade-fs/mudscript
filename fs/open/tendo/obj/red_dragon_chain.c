#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIR + "火雲龍鎖" + NOR,({"red_dragon_chain","chain"}));
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
                set("value",30000);
                set("material","crimsonsteel");
                set("rigidity",70);
                set("long","一條" + HIR + "火紅" + NOR + "的鎖鏈,是由" + HIY + "陸清風" + NOR + "打敗上古生物火龍,扒其筋骨製作而成的。\n");
        set("wield_msg", "$N將$n挽在手上,一股" + MAG + "龍氣" + NOR + "便由你的手臂直傳而上。\n");
        set("unwield_msg","$N手上的" + MAG + "龍氣" + NOR + "迅速傳回" + HIR + "鎖鏈" + NOR + "中。\n");
        }
        init_whip(90);
        setup();
}
