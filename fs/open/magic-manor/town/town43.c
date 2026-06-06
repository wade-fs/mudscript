inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "小森林");
	set( "build", 1 );
        set ("long", @LONG
從草原一路再走來，兩旁的小草不知何時已漸漸的換成較高大的
樹木了，你不時的還要揮劍劈開兩旁擋路的小樹枝，動物們的叫聲也
愈來愈狂。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town44",
        "west"	: __DIR__"town42",
	]));

        setup();
}
