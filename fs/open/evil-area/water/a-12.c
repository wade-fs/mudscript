inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
漫步於琰揚湖旁，你有一種前所未有的舒適感，或許是週遭的生
物才會帶給你如此強烈的感覺吧，先前只要在路上碰到此等生物，二
話不說，必定兵戎相見，現今卻是相安無事的彼此做的彼此的事情，
所以你才會有這麼強烈的感覺。
在一旁，你看到了一個擺著地攤的人類，地上擺滿了許多新奇的東西
，你十分好奇著張望著。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-13",
"east":__DIR__"a-29",
"north":__DIR__"a-11",
]));
	setup();
}

 
