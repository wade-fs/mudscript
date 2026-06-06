inherit ROOM;
#include <ansi.h>


void create()
{
        set("short","樓梯");
	set( "build", 2 );
        set("long", "一個極其簡單的直立式樓梯，歷經常年的歲月洗禮，已變的破舊
不堪，可以通往靈塔七樓。\n");
        set("exits", ([
	"up"	: __DIR__"infire",
        ]));
	set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
	setup();

}

