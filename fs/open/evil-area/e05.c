inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",BBLU+YEL"震邪道"NOR);
	set("long",@LONG
再一個閃耀著金黃色光芒的四方形空間內, 有一個黃金守衛正在
站立在一道雕碩精美的黃金門前, 黃金守衛的雙目直盯著所有踏入這
房間內的人, 當然, 也包括你在內...
LONG);
	set("objects",([
__DIR__"npc/golden_guard":1,
]));
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"e04",
]));
	setup();
}

