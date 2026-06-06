inherit ROOM;
#include <ansi.h>
#include "tree.c"

void create()
{
	set("short",HIG"琰 揚 居 -- "NOR+YEL"大 松 樹"NOR);
	set("long",@LONG
漸漸地，你已經可以清楚的看到了這棵大松樹的最頂端，不過，
你也漸漸地聽到了一種聲音，〔嗡～嗡～〕，並且....越來越大聲，
彷彿是一種警告的聲音。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"up":__DIR__"b-44",
"down":__DIR__"b-42",
]));
	setup();
}
