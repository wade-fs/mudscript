inherit ROOM;
#include <ansi.h>
#include "war.c"

void create()
{
	set("short",HIB"海神廟-廳堂入口"NOR);
	set("long",@LONG
  眼前是海神廟廳堂的入口，整個海神廟可以說是浮在海洋之上，
廳堂的入口兩側有兩條龍攀升而上的乳白石柱，在兩個石柱中，有一
道炫麗的橢圓鏡面，不斷的在旋轉、發光！
LONG);
	set("item_desc",([
	"橢圓鏡面":"接觸(touch)鏡面，將可進入海神廳堂\n",
	"鏡面":"接觸(touch)鏡面，將可進入海神廳堂\n",
]));
	set("defence-build",10);
	set("exits",([
"west":__DIR__"s14",
]));
	setup();
}

void init()
{
	add_action("do_touch","touch");
}

int do_touch()
{
	message_vision(HIC"$N接觸了鏡面，人一瞬間被吸入其中！\n"NOR,this_player());
	this_player()->move(__DIR__"s16");
	return 1;
}
