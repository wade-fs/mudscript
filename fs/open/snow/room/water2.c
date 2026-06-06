#include <room.h>

inherit ROOM;
void do_west();
void create()
{
            set("short","雪泉");
	set( "build", 12 );
      set("long",@LONG
這裡是雪蒼山的山腳﹐往西通往雪泉﹐相傳雪泉中的雪泉聖水
有神奇的魔力﹐但是在雪泉中有傳說中的守護聖獸把守著﹐而
且聖水的位置到底在那﹐也是一個問題﹐不少英雄豪傑﹐進入
雪泉都無功而返。
LONG);
        set("exits", ([
		"east":__DIR__"room3",
		"west":__DIR__"water",
               "northdown":__DIR__"black1",
        ]) );
	set("objects",([
		"/open/snow/npc/taoist" : 1,
		]));
	set("light_up",1);
        setup();
}
