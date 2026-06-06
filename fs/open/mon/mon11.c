inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "登山小徑");
	set( "build", 12 );
        set ("long", @LONG
走到這裏，路況一轉，你得繞一個大彎才能更往前進，而且路面
也愈來愈抖，愈往前走，路愈是難走，前面的路已經愈來愈小條了，
若非懷著絕世輕功的人走上這條路將會倍感吃力，但通往山上的小路
依舊清楚可見。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"mon12",
        "west"  : __DIR__"mon10",
]));
        setup();
}

