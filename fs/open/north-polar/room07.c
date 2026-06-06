inherit ROOM;
#include <ansi.h>
#include "ice.msg"
#include "icestorm.c"

void create()
{
        set("short",HIW + "極北冰原" + NOR);
        set("long", (: printf_msg :) );
        set("exits", ([
	"north"	: __DIR__"room06",
	"south"	: __DIR__"room08",
	"enter" : __DIR__"main",
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
        if( dir=="enter" && !userp(me) )    
                return 0;                  
                                           
        return ::valid_leave( me, dir );   
} 
