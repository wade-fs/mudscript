inherit ROOM;
#include <ansi.h>
#include "ice.msg"
#include "icestorm.c"

void create()
{
        set("short",HIW"極北冰原"NOR);
        set("long", (: printf_msg :) );
        set("exits", ([
	"east"	: __DIR__"room21",
	"west"	: __DIR__"room19",
        ]));
        set("objects",([
                        __DIR__"npc/mob1" : 1,
                        __DIR__"npc/mob2" : 1,
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
	set("no_chome",1);
	set("no_quit",1);
	set("no_scale",1);
        setup();

}
