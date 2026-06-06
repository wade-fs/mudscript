inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "雲風西道");
        set ("long", @LONG
走到這裏，你好似來到一個繁華的地方，不遠處還傳來陣陣小孩
的嘻鬧聲，走道被修飾的整齊清潔，來往的人潮也漸漸的多了，讓你
有一股溫暖的感覺。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town13",
        "west"	: __DIR__"town41",
	]));

        setup();
}
