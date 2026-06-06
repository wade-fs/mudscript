//虹晶頭釵---2000.4.3 by dhk
#include <armor.h>
#include <ansi.h>

inherit HEAD;
void create()
{
        set_name(HIM + "虹晶頭釵" + NOR, ({"diamond hairpin", "hairpin"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", "一件由北勝天使用〝虹晶〞特異礦石鑄成，表面散發著特異的紫光，是萬年的寶物。\n");
        set("unit", "支");
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
        set("value", 300000);
        set("material", "diamond");
        set("armor_prop/armor", 10);
        set("armor_prop/dodge",7);
        set("armor_prop/move",7);
        set("armor_prop/stabber",8);
        }
        setup();
}

