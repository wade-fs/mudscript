inherit ROOM;
#include <ansi.h>
#include "tree.c"

void create()
{
	set("short",HIG + "琰 揚 居 -- "NOR+YEL"大 松 樹" + NOR);
	set("long",@LONG
大松樹的樹幹充滿的許多的坑洞，看到此景的你，忍不住的替這
棵樹感到哀痛，不過，卻也因為有了這些樹洞，你才能順利的爬上樹
上去，真是令人無法去評斷這事情的好壞。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"up":__DIR__"b-30",
"down":__DIR__"b-28",
]));
	setup();
}
