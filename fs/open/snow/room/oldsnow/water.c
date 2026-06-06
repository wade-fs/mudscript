#include <room.h>

inherit ROOM;
void do_west();
void create()
{
      set("short","雪泉入口");
      set("long",@LONG
眼前所見是一座山泉﹐在山壁上流著潺潺泉水﹐相傳雪泉泉水
有神奇的魔力﹐但是在雪泉中有傳說中的守護聖獸把守著﹐而
且聖水的位置到底在那﹐也是一個問題﹐不少英雄豪傑﹐進入
雪泉都無功而返。
LONG);
        set("exits", ([
		"east":__DIR__"water2",
        ]) );
	set("light_up",1);
        setup();
}
void init()
{
}
int do_enter(string str)
{
     if(str!="water")
         return 0;
     if(!present("snow token",this_player()))
         return notify_fail("要有雪泉聖物才能進入雪泉。\n");
     tell_object(this_player(),"你走進泉水之中。\n");
      this_player()->move(__DIR__"water3");
     return 1;
}
