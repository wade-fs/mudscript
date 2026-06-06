inherit ROOM;
#include <ansi.h>
#include "war.c"

void create()
{
	set("short",HIB + "海神廟-廳堂" + NOR);
	set("long",@LONG
  要說四周是十分的狹窄，還是說十分的空曠，你也說不上來，一
切都是乳白色的四周，根本分不清楚四周的範圍是多大，彷彿空間對
這裡來說是沒有意義的事情！
LONG);
	set("objects",([
	__DIR__"npc/god":1,
	]));
	setup();
}

void init()
{
	add_action("do_touch","touch");
}

int do_touch()
{
	message_vision(HIC + "$N接觸了鏡面，人一瞬間被吸入其中！\n" + NOR,this_player());
	this_player()->move(__DIR__"s15");
	return 1;
}
