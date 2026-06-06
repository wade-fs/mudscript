inherit ROOM;
#include <ansi.h>
#include "tree.c"
#include "tree.msg"

void create()
{
	set("short",HIG + "琰 揚 居 -- " + NOR+YEL + "大 松 樹" + NOR);
	set("long",(: printf_tree :));
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"up":__DIR__"b-34",
"down":__DIR__"b-32",
]));
	setup();
}
