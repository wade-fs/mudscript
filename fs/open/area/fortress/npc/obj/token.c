#include <ansi.h>
inherit ITEM;			//單一道具

void create()
{
	set_name(YEL"令牌"NOR, ({"token","fortress token"}));	//名稱
	set_weight(100);					//重量
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","四四方方的令牌，在令牌正反兩面均有一個火焰的形狀。\n");
		set("base_unit", "面");			//單數道具的單位
		set("value", 10);			//價值，以coin計算
	}
	setup();
}
