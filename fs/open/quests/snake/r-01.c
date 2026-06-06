inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","蛇寨 大門");
	set( "build", 12 );
	set("long","這裡是蛇寨的大門，門口處長滿了許\多的藤蔓，若不仔細搜查，
還真的不容易發現大門的位置，不過在這個山寨的上方，有兩個石製
的蛇頭就顯的非常的明顯，彷彿是在警告著來者，請勿輕易入洞，免
得慘招毒蛇之吻...

			"+HIG+"<蛇寨>\n" + NOR);
	set("exits",([
"west":"/open/main/room/s22",
]));
	setup();
}

void init()
{
add_action("do_enter","enter");
}

int do_enter()
{
object me = this_player();

	message_vision("$N撥開藤蔓，推開大門後，走了進去。\n",me);
	me->move(__DIR__"r-02");
return 1;
}
