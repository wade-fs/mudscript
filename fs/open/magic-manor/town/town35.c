#include <ansi.h>
#include "/open/open.h"
#include <room.h>

inherit "/std/room/hockshop";

void create ()
{
        set ("short", "當鋪");
        set ("long", @LONG
人總有失意落魄的時候，所以鎮上的一個居民就想為鎮民服務，
開了這家小當鋪，可以典當各式各樣值錢的東西，以換取一點點的金
錢做為救急所用。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town29",
	]));

        setup();
}
