// Room: /open/ping/room/graveyard.c

#include <ansi.h>

inherit ROOM;

void create ()
{
	set( "short", HIB"︿"HIG""GRN""HIG""GRN""HIG""GRN"^"HIB"︿"NOR );
	set( "long", @LONG

    四周一片漆黑, 隱約可以看見幾棵枯萎的白楊樹, 狂風吹過樹梢, 發出
淒厲的嘯聲。到處都是傾倒的墓碑, 在崩塌的墳墓上還有慘綠的燐火在半空
中飄盪, 從淡淡的綠光中隱約可以看到從墳墓中露出一角的棺材裡面隱隱傳
出陣陣地哭嚎聲, 讓人毛骨悚然, 在這亂葬崗的下頭不知藏著什麼秘密。這
裡妖魔鬼怪混雜, 秩序紊亂, 任誰也不想在這多待一秒, 但在這卻站了一位
神秘老者。       

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"road12",
	]));
	set("outdoors", "/open/ping");
	set("objects", ([ /* sizeof() == 1 */
		"/open/ping/npc/death" : 1,
]));
	setup();
	replace_program(ROOM);
}

                               
