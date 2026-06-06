#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name("連環獸面鎕猊鎧",({"plate"}) );
	set_weight(10000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","
鎕猊為產於西域的一種野獸，性情殘暴，外皮堅硬，刀槍不入。西域番邦
將其擒獲，剝其外皮硝製製成這件鎧甲進貢給朝廷。朝廷為了紀念將軍保
護疆土有功\，而賜與這件鎧甲。\n");
		set("unit","件");
		set("value",10000);
		set("material","crimsonsteel");
		set("armor_type","cloth");
		set("armor_prop/armor",20);
		set("armor_prop/parry",5);
		set("armor_prop/dodge", -5);
		setup();
	}
}
