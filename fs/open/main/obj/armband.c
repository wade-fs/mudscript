
#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name(HIR"赤"+HIG"麟"+HIC"肩甲"NOR,({"Red chilin armband","armband"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","當年綠毛老祖大戰赤燄麒麟七七四十九天，從赤燄麒麟身上的鱗片所提煉而成。");
        set("unit","個");
        set("value",1750);
        set("material","crimsonsteel");
        set("armor_type","armbands");
          set("armor_prop/armor",10);
        set("armor_prop/unarmed", 10);
        set("armor_prop/dodge", 10);
        }
        setup();
}
int query_autoload()
{
      return 1;
}
