
#include <weapon.h>
#include <ansi.h>
inherit LANCE;
void create()
{
        seteuid(getuid());
set_name(HIM"紅剡"NOR,({"sharpen"}));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
    set("long","
    這把利器是跟藍劫一起從黃果山瀑布水底打撈出來的
據說挖出來時是兩把合在一起的..然後由名鐵匠皮古日夜
切割..才分成兩把槍。
    ");
                set("value",70000);
                set("material", "blacksteel");
        set("wield_msg", "$N背一斜,順勢抽出$n,$n漸漸發出耀眼的屬光,頓時$N充滿力量。\n");
        set("unwield_msg", "$N將手中$n放回背上的刀囊中。\n");
      }
        init_lance(85);
        setup();
}


