// Room: /open/start/room/s12.c

#include "../start.h"

inherit ROOM;

void create ()
{
	set ("short", "房舍");
	set ("long", @LONG
這裡是凌雲村村長的住屋，由於不想讓外地來的人干擾到
村人們的生活，所以要借宿只能在這兒。
    西面那間房舍就是專門讓人借宿用的，如果你想借宿暫時
休息一下，你可以問問村長。
    另外村長也兼作小販的生意。

LONG );

	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"s13",
	"south" : __DIR__"s11",
	]));

	set("objects", ([ /* sizeof() == 1 */
	S_NPC"sheik" : 1,
   "/open/start/npc/test" : 1,
	]));

	set("light_up", 1);

	setup();
}

int valid_leave(object who, string dir)
{
	if( dir=="west" && !who->query_temp("sleep") )
		return notify_fail("你還沒問過村長呢！\n");
	return ::valid_leave(who, dir);
}
