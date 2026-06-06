inherit ROOM;
#include <ansi.h>
#include "war.c"

void create()
{
	set("short",HIB"海神廟"NOR);
	set("long","
一片汪洋大湖踩在腳底，唯一能觸碰的東西，只有沿著淺灰色不
斷向兩側延伸的圍牆與一道粉白色貝殼門；腳底踩著起伏不定的波浪
一高一低的令人感覺不踏實。
");
	set("defence-build",10);
	set("exits",([
"north":__DIR__"s02",
]));
	setup();
}

void init()
{
add_action("do_out","out");
}

int do_out(object me)
{
me = this_player();

	message_vision(HIC"$N走出海神廟\n"NOR,me);
	me->move("/open/area/forest/sh07");
return 1;
}
