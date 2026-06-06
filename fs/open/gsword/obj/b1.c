// 劍陣新寫法成功，so 此劍原本的劍陣特功取消

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("古鏽劍",({"old sword","sword"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop",1);
		set("long","一把年代久遠的鏽劍。\n");
	/*	set("value",1000);	*/
		set("material", "gold");
		set("no_sell",1);
		set("no_give",1);
		set("no_auc",1);
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
              set_heart_beat(1);
	}
	init_sword(10);
	setup();
}

