inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(RED + "火鶴焰汁" + NOR,({"food","evil-foods"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
	else
	{
		set("value",10);
		set("base_unit","盤");
		set("unit","大盤");
		set("long","這是由鈺萍姊所精心調製的食物之一，不過...似乎不是普通人所能〔吃〕的下口...\n");
	}
	set_amount(1);
setup();
}
