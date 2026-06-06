#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIC + "七" + HIM + "彩" + HIW + "羽" + HIG + "衣" + NOR, ({ "seven color feather","feather"}) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
                set("unit", "件");
		set("value",1000000);
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("long","
謠傳這是天界所傳下來的天衣製法所製成的，穿上它後可以像天仙
一樣翱翔天際﹔可惜由於太過於貴重，很多仿製品紛紛出籠，如今
已有許\多人上當了。\n");
        }
        setup();
}
