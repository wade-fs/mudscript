// coffin.c by powell

#include <ansi.h>
#include "/open/open.h"

inherit ITEM;

void create()
{
	set_name(YEL "棺木" NOR,({"coffin"}) );
	set("long", "一口長滿青苔的棺木, 似忽已擺\在這有好多年了。\n"+
	            "也許\你想移開(move)棺蓋\, 瞧一瞧裡面有甚麼, 不過"+
	            "很有可能有未知的"+HIR+"危險"+NOR+"喔。\n");
	set("unit", "口");
	set_weight(5000000);
	set("value",1);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	int maxf,killair,check;
	object who;
	who = this_player();
	maxf = who->query("max_force");
	killair = who->query("bellicosity");
	check = who->query_temp("coffin");
	if ( arg == "coffin" ) {
	if ( killair > 100 && check !=1 ) {
	message_vision( "突然, 你感覺到四周有點說不出的詭異....\n"+
			"一個影子由模糊而清晰的出現在$N的面前。\n\n",who);
	tell_object( who,"惡人守護靈邪惡的對著你笑道：\n"+
		         "你真的想要搬動這個棺木嗎?\n\n");
	message_vision( "影子對著$N說了句話後, 就再次由清晰而模糊, "+
	                "最後消失不見。\n",who);
	who->set_temp("coffin",1);
	return 1;
	}	         			
			
	message_vision( "$N用力搬開棺蓋\, 一股濁黑的污氣向著$N的臉上噴去。\n",
			who );
	tell_object( who, "你感到身體十分不適, 全身虛弱。\n");
	if ( maxf > 50 ) {
	who->add("max_force",-50);
	return 1;
	}
	who->set("kee",1);
	who->set("gin",1);
	who->set("sen",1);
	return 1;
	}
	tell_object( who, "你想要搬動甚麼???\n" );
	return 1;
}

