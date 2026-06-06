inherit ROOM;
#include <ansi.h>

string *exit = ({ __DIR__"gold09",__DIR__"gold10",__DIR__"gold11",__DIR__"gold12",});

void create()
{
        set("short","樓梯");
        set("long", "一個極其簡單的直立式樓梯，歷經常年的歲月洗禮，已變的破舊
不堪，可以通往靈塔三樓。\n");
        set("exits", ([
	"up"	: exit[random(sizeof(exit))],
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
        setup();

}

