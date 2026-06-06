// dragon_sword.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit SSERVER;

void create()
{
	set_name(HIY + "穿龍劍" + NOR,({"dragon sword","sword"}));
	set("靈氣量",120);
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",10000);
		set("material","steel");
		set("long",@LONG
這把是獨孤世家世代相傳的寶物之一﹐相傳這把劍
不但有削鐵如泥之能﹐還具有一種神奇的魔力﹐但是﹐
使用的方法只有獨孤世家的人知道。
LONG);
		set("wield_msg",@LONG
只見$N抽出了$n之後寒光似射﹐一團團的劍氣已包圍在$n周圍﹗
LONG);
	}
	init_sword(50);
	setup();
}
void init()
{
	add_action("do_cast","power");
}
int do_cast(string arg)
{
	object ob = offensive_target(this_player());
	if( !ob ) return 0;
	if( arg != "sword" ) return 0;
	if( query("靈氣量") <= 0 ) {
		tell_object(this_player(),"你的穿龍劍已經失去了靈氣﹐無法再使用。\n");
		return 1;
	}
	message_vision(
	HIR + "$N一聲大喝﹕手中穿龍劍發出一陣雷鳴﹐只見一條赤龍鑽出﹗\n" + NOR,
	this_player());
	message_vision(
	HIR + "只見赤龍在$n身邊穿過﹐$n血流如柱﹗\n" + NOR,this_player(),ob);
	ob->receive_wound("kee",query("靈氣量"));
	COMBAT_D->report_status(ob);
	add("靈氣量",-random(20));
	this_player()->start_busy(3);
	return 1;
}
