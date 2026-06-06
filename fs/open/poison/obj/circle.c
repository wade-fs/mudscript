
#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name("金圈",({"golden circle","circle"}));
	set_weight(5000);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一對對以純金打造而成的金圈，套在小腿上美觀又可增添防禦性，走起路來聲音
鏗鏘，十分動聽。\n");
		set("unit","個");
		set("value",1000);
		set("armor_prop/armor",9);
		set("armor_prop/parry",6);
		set("material","gold");
		set("armor_type","boots");
		setup();
	}
}
