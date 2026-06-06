
#include <ansi.h>

inherit EQUIP;

void create()
{
    set_name(HIY + "九天玄女" + HIW + "羽裳" + NOR,({"goddness cloth","cloth"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
else	{
	set("meterial","silk");
	set("unit","件");
	set("value", 1000);
	set("armor_type","cloth");
	set("armor_prop/armor",25);
   set("armor_prop/dodge", 10);
    set("armor_prop/whip",8);
	set("long","
一件不知用甚麼質料製成的衣裳，上面隱隱約約散發著迷濛的色彩，穿上它
似乎便有神力保護著。\n");
	}
	setup();
}
