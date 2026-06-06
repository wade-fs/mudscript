inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "于風的家");
	set( "build", 24 );
        set ("long", @LONG
鎮上最令人稱羨的一對情侶之一，于風的家，一間看來和一般民
宅沒兩樣的一間房子，所有的傢俱也都清理的很整潔，排放的也井然
有序。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "south"  : __DIR__"town11",
]));
        set("light_up", 1);
        setup();
}
