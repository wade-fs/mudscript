inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "防具店");
        set ("long", @LONG
雲風鎮裏面唯一的一間防具店，件件防具是堅固又耐穿，件件都
是精心製作，店的後方還有一套金光閃閃的防具擺在那裏，是店裏的
鎮店之寶。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "south"  : __DIR__"town08",
]));
        set("light_up", 1);
        setup();
}
