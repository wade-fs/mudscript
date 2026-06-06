//丐幫weapon武器強度未定
//重量和價值需重新比照 by guetenr
#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
       set_name(HIG"綠竹青棍"NOR, ({ "green staff","staff","green" }) );
       set_weight(800);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "這是丐幫高階長老才有的棍子.\n");
                set_weight(800);
                set("material","wood");
        }
       init_staff(20);  //由於太好拿到，故將其攻擊力降低為20  by pana

// These properties are optional, if you don't set them, it will use the
// default values.

       set("wield_msg", "$N輕鬆的將$n握在手中﹐順心舞弄。\n");
       set("unwield_msg", "$N將手中的$n隨手插入背後。\n");

// The setup() is required.

        setup();
}

