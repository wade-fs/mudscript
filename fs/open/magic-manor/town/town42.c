//AM 09:52 2001/9/16 bye neverend

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "小草原");
	set( "build", 1 );
        set ("long", @LONG
離開風雲鎮一直往東方前進，只覺得人煙愈來愈少，路也愈來愈
難走了，眼前的景象盡是一望無際的草原，還不時可以聽到一些動物
的叫聲，似乎是來到了蠻荒的地方。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town43",
        "west"	: __DIR__"town39",
	]));

        setup();
}
