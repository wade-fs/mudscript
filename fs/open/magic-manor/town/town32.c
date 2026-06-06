inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "水果攤");
	set( "build", 12 );
        set ("long", @LONG
販售各種各樣新鮮的水果，水果的香味四溢，讓遠在幾百公尺的
你都聞香趕來，只見粒粒果實大小勻稱，汁多飽滿，味道更是鮮美的
無話可說。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town26",
	]));

        setup();
}
