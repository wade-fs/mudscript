inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "賞雲坡");
	set( "build", 21 );
        set ("long", @LONG
山風輕拂，浩翰的雲海就在眼前，心中一陣說不出的舒爽，你有
如站在雲端，傲視萬物，視野所見都是美，是一處極佳的賞雲地點，
令人留連忘返。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "north"      : __DIR__"mon28",
]));
        setup();
}

