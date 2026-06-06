inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "鎮長的家");
	set( "build", 12 );
        set ("long", @LONG
由入門到進入這間屋子，所有的一切都顯得氣派輝皇，和一般的
民宅有天壤之別，雖然鎮長稱不上大富大貴，但是卻比一般的人還要
富有的多。讓你不敢小覷鎮長的能力。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "south"  : __DIR__"town12",
]));
        set("light_up", 1);
        setup();
}
