inherit ROOM;
#include <ansi.h>

string *exit = ({ __DIR__"fire17",__DIR__"fire18",__DIR__"fire19",__DIR__"fire20",});

void create()
{
        set("short","樓梯");
        set("long", "一個極其簡單的直立式樓梯，歷經常年的歲月洗禮，已變的破舊
不堪，可以通往靈塔五樓。\n");
        set("exits", ([
	"up"	: exit[random(sizeof(exit))],
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
        setup();

}

