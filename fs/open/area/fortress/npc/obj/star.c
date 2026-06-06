#include <ansi.h>
inherit ITEM;			//單一道具
inherit F_AUTOLOAD;
void create()
{
	set_name(YEL"土靈。焚天珠"NOR, ({"soil pearl","pearl"}));	//名稱
	set_weight(1000);					//重量
        set("no_auc",1);
        set("no_sell",1);
        set("no_put",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","焚天魔王遺留在世人間的五顆魔珠之一，此顆為土靈珠。
	使用方式：turn_on 、 turn_off\n");
		set("unit","顆");
		set("base_unit", "顆");			//單數道具的單位
		set("value", 10000);			//價值，以coin計算
	}
	setup();
}

int query_autoload()		//自動載入
{
    return 1;
}

void init()
{
	add_action("do_turn_on","turn_on");
	add_action("do_turn_off","turn_off");
}

int do_turn_on(string arg)
{
	object ob=this_object();
	if(!arg)	return 0;
	if(arg!="pearl" && arg!="soil pearl")	return 0;
	if(this_player()->query_temp("turn_on/pearl-1"))	return notify_fail("仍在運作中。\n");
	else
	{
		message_vision(HIY"$N轉動著$n。\n
$n"HIY"在$N手心緩緩旋轉，慢慢漂浮離開$N的手，環繞在$N的身旁並發出強烈的黃色光芒！\n"NOR,this_player(),ob);
		//ob->set("no_get",1);
		//ob->set("no_auc",1);
		//ob->set("no_give",1);
		//ob->set("no_put",1);
		//ob->set("no_sell",1);
		//ob->set("no_sac",1);
		//ob->set("no_drop",1);
		ob->set_name(HIC"《"HIG"驅動中"HIC"（"HIY"黃光"HIC"）》"YEL"土靈。焚天珠"NOR,({"soil pearl","pearl"}));
		this_player()->set_temp("turn_on/pearl-1",1);
		this_player()->apply_condition("turn_on_pearl-1",1);
	}
	return 1;
}

int do_turn_off(string arg)
{
	object ob=this_object();
	if(!arg)	return 0;
	if(arg!="pearl" && arg!="soil pearl")	return 0;
	if(!this_player()->query_temp("turn_on/pearl-1"))
		return notify_fail("沒有啟動。\n");
	{
		message_vision("$n"HIY"緩緩降落在$N的手中，光芒也漸漸消失了...\n"NOR,this_player(),this_object());
		this_player()->delete_temp("turn_on/pearl-1");
		//ob->delete("no_get",1);
		//ob->delete("no_auc",1);
		//ob->delete("no_give",1);
		//ob->delete("no_put",1);
		//ob->delete("no_sell",1);
		//ob->delete("no_sac",1);
		//ob->delete("no_drop",1);
		ob->set_name(YEL"土靈。焚天珠"NOR, ({"soil pearl","pearl"}));
	}
	return 1;
}
