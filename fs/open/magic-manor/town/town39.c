inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "雲風東道");
	set( "build", 12 );
        set ("long", @LONG
走到這裏，你好似來到一個繁華的地方，不遠處還傳來陣陣小孩
的嘻鬧聲，走道被修飾的整齊清潔，來往的人潮也漸漸的多了，讓你
有一股溫暖的感覺。而東方的密林，是大家所害怕去的地方，因為有
許多的鎮民，走進去之後就再也出不來了，所以都不敢隨便的進入。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town42",
        "west"	: __DIR__"town24",
	]));

        setup();
}
