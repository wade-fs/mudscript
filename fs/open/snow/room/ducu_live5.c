#include <room.h>

inherit ROOM;

void create()
{
	set("short","觀風軒");
	set("long",@LONG
 
 
LONG);
        set("exits", ([
	"south":__DIR__"ducu_live3",
        ]) );
	set("light_up",1);
        setup();
}
