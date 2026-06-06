#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "傳送光牆");
	set ("long", @LONG
極大的一片光牆呈現在眼前，似乎可以(walk)進去似的，還在猶
豫要不要走進去的你，漸漸的有一股吸力將你慢慢的往光牆推過去，
耳邊還不時的傳來震天雷響的聲音。

LONG);

	set("no_auc", 1);
	set("no_transmit", 1);
	set("no_chome", 1);
	set("light_up", 1);

	setup();
}

void init()
{
	add_action ("do_trans","walk");
}
int do_trans (string str)
{
	object me = this_player();
	message_vision(HIW"$N慢慢的走進了光牆之中，消失了!!\n"NOR,me);
	me->move("/open/magic-manor/manor57");
	message_vision(HIW"$N轉眼間又回到了祭臺的入口了!!\n"NOR,me);
	return 1;
}
