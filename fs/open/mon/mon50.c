inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "接天境");
	set( "build", 36 );
        set ("long", @LONG
登上這裏，這裏的景色真是你所見過最美的了，縹渺的雲霧輕輕
的漫舞在你的身旁，七色的炫光直通天際，沉浸在這樣的景色之中，
你不禁有些迷失了，卻已忘了你是身處夢中還是現實之中。
LONG);
        set("outdoors", "");
        set("exits", ([
        "down"    : __DIR__"mon42",
	]));
	set("objects", ([
	__DIR__"npc/flower" : 1,
]));
        setup();
}
