#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山洞");
	set("long", @LONG
這裡是峭壁裡的山洞，雖然說是個山洞，不過還是頂乾靜的，在這
裡你還可以聽見清析的滴水聲。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"cave",
            "east"  : __DIR__"cave2",
]));
	setup();
}



