inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",BBLU+YEL + "震邪道" + NOR);
	set("long",@LONG
你的頭頂上, 正漂浮著有如波浪斑波動的細沙, 你有一種直覺, 
那裡似乎就是通往堆滿了沙堆的磚瓦屋內; 在你眼前, 東南西北四
個方向各有一扇木門, 除此之外, 什麼也沒有... 
LONG);
	set("exits",([
"jump":__DIR__"e02",
"north":__DIR__"room",
"south":__DIR__"room",
"east":__DIR__"room",
"west":__DIR__"room",
]));
	set("no_transmit",1);
	setup();
}
