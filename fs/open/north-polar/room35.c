inherit ROOM;
#include <ansi.h>
#include "ice.msg"
#include "icestorm.c"

void create()
{
        set("short",HIW"極北冰原"NOR);
        set("long", (: printf_msg :) );
        set("exits", ([
	"northwest"	: __DIR__"room34",
	"southeast"	: __DIR__"room36",
        ]));
        set("objects",([
                        __DIR__"npc/mob3" : 2,
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
	set("no_chome",1);
	set("no_quit",1);
	set("no_scale",1);
        setup();

}
