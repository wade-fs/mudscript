inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "翠柳的家");
	set( "build", 24 );
        set ("long", @LONG
鎮上最令人稱羨的一對情侶之一，翠柳的家，房子的的佈置上似
乎豪了許多，廳堂上的桌椅都是經過名師所雕刻的，顯出這家的豪華
與氣派，是一個有錢人的人家。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "north"  : __DIR__"town11",
]));
        set("light_up", 1);
        setup();
}
