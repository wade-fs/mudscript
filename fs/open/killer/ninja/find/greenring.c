#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("綠毛金鈴", ({ "green_ring" }) );
        set("long","有著詭異的綠色的金屬鈴鐺，拿去給柴榮吧\n");
        set_weight(10);
        set("unit", "個");
        set("value", 0);
        set("no_sell", 1);
        set("no_auc", 1);
        set("no_drop", 1);
        
        setup();
}
