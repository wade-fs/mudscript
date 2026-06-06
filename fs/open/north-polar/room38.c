inherit ROOM;
#include <ansi.h>
#include "ice.msg"
#include "icestorm.c"

void create()
{
        set("short",HIW"極北冰原"NOR);
        set("long", (: printf_msg :) );
        set("exits", ([
	"northwest"	: __DIR__"room37",
	"southeast"	: __DIR__"stela2",
	"up"            : __DIR__"store",
        ]));
        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
	set("no_chome",1);
	set("no_quit",1);
	set("no_scale",1);
        setup();

}


int valid_leave( object me, string dir )   
{                                          
        if( dir=="up" && !userp(me) )    
                return 0;                  
                                           
        return ::valid_leave( me, dir );   
}  
