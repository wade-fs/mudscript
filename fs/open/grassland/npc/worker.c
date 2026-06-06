// /open/center/npc/vendor.c
#include <obj.h>
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("防具工人", ({ "equip worker", "worker" }) );
	set("long","這位工人可以協助把印鑲進防具裡面。\n");
	set("attitude", "friendly");
	set("inquiry",([
		"印":"這是一項非常神奇的物品，可以鑲在防具裡面，來加強防具的功\能。",
		"鑲":"鑲一次除了需要印之外，我還想收點一顆鑽石來當工本費呢！\n"+
		      "\t\t如果成功\的話，可以永久的加強防具的特別效果。\n"+
			  "\t\t如果失敗的話，這件防具會變成癈鐵呢。\n"+
			  "\t\t如果都準備好的話，可以用metallurgy來請我幫忙鑲進去。\n",
	]));
	set("combat_exp",30000000);
	set_temp("apply/dodge",500);
	set_temp("apply/parry",500);
	setup();
}
void init()
{
	add_action("do_metallurgy","metallurgy");
}
void success(object me,object itemob,object eqob)
{
	CHANNEL_D->do_channel(me,"chat",
		sprintf("哈哈哈，成功\的把%s鑲進%s中。",itemob->name(),eqob->name()));
	destruct(itemob);
}
int do_metallurgy(string arg)
{
	string item,eq,type;
	object itemob,eqob,me;
	int power,sum;
	me = this_player();

	
	if(!arg || sscanf(arg,"%s on %s",item,eq) != 2)
	    return notify_fail("請用 metallurgy [item] on [eq]\n");
	
	if(!itemob = present(item,me))
		return notify_fail(name()+"說道：你身上沒有這個寶物。\n");
	if(!eqob = present(eq,me))
		return notify_fail(name()+"說道：沒有這件防具。\n");
	if(!eqob->query("armor_type"))
		return notify_fail(name()+"說道：這件不是防具。\n");
	if(eqob->query("equipped"))
		return notify_fail(name()+"說道：正在穿著的防具不能鑲進寶物。\n");
	if(!itemob->query("item_type"))
		return notify_fail(name()+"說道：這類寶物不能鑲進防具裡。\n");
	if(!me->can_afford(100000000))
		return notify_fail(name()+"說道：我需要酌收一顆鑽石為工本費，但你身上的錢不夠。\n");
	me->pay_money(100000000);
	sum = 0;
	me->delete_temp("last_channel_msg");
	this_object()->delete_temp("last_channel_msg");
	if(sizeof(eqob->query_temp("extra_power/file")))
	{
		foreach(int time , string file in eqob->query_temp("extra_power/file"))
		{
			sum++;
		}
	}
	if(random(sum+1) != 0)
	{
		CHANNEL_D->do_channel(this_object(),"mud",
			sprintf(HIR + "一陣火花從狂想某地竄出，%s的%s" + HIR + "竟然打造失敗而成為一塊癈渣。\n" + NOR
				,me->name(),eqob->name()));
		destruct(eqob);
		destruct(itemob);
		return 1;
	}
	type = itemob->query("item_type");
	power = itemob->query("item_power");
	eqob->add_temp("extra_power/apply/"+type,power);
	eqob->set_temp("extra_power/file/"+time(),base_name(itemob));
	call_out("success",2 , me,itemob,eqob);
	log_file("sky/meta",sprintf("[%s] %s:%s:%s:%s:%d\n",
		ctime(time()),me->query("id"),eqob->short(),itemob->short(),type,power));
	tell_object(me,this_object()->name()+"一陣手忙腳亂，開始加強"+eqob->name()+"了。\n");
	me->start_busy(2);
	return 1;
}
