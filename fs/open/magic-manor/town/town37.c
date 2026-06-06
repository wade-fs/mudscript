inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "廣場中央");
	set( "build", 48 );
        set ("long", @LONG
廣場的正中央，是所有鎮民活動的地方，寬廣的廣場，聚集了不
少鎮民在此活動，熱鬧的景象，讓這小鎮活絡了起來，可以看見鎮民
在那聊天、泡茶、乘涼、嬉戲、遊樂，這樣的景象真是羨煞了江湖兒
女心的你，也好想這麼樣悠閒的過活兒。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "northeast"	: __DIR__"town16",
        "southeast"	: __DIR__"town22",
        "northwest"	: __DIR__"town15",
        "southwest"	: __DIR__"town21",
	]));

    set("objects", ([ /* sizeof() == 4 */
   "/open/magic-manor/npc/stone-sky" : 1,
	__DIR__ "npc/kid01"	: 1,
	__DIR__ "npc/kid02"	: 1,
	__DIR__ "npc/oman"	: 1,
	]));

        setup();
}
