inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "西北廣場");
	set( "build", 12 );
        set ("long", @LONG
雲風鎮中的廣場西北角，這是雲風鎮中所有居民們休息聊天的場
所，偶而有些武林俠客也會利用這地方比武，還有三五個小孩不時的
在這廣場中成群的嬉戲遊玩，好不快樂。北方接著北鎮道。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"      : __DIR__"town09",
        "south"      : __DIR__"town21",
        "east"       : __DIR__"town16",
        "southeast"  : __DIR__"town37",
	]));

	set("objects", ([ /* sizeof() == 1 */
	__DIR__ "npc/oman"	: 1,
	__DIR__ "npc/woman"	: 1,
	]));

        setup();
}
