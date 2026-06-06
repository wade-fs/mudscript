#include <room.h>

 inherit ROOM;

 void create()
{
set("short"," ^EP^\C^L^C^Dj^J^Y ");
        set("long", @LONG
                                                                   
                                                                   
        
                                                 
         ╭╯   ║         ╭╮       ║       ╭╯╭        
       ╭╯     ║       ╭╯╰╮     ║   ╮  ╯╭╯   
     ╭╯║     ║     ╭╯══╰╮║ ║   ╰   
         ║     ║       ─╖ ─╖ ║ ║   ╮ ║ ║
         ║     ║      ║ ║║ ║    ║   ╰ ║ ║ ╮ ●
         ║ ║  ║  ║  ╙─ ╙─     ║      ║ ║ ╰╮
         ║ ╰═╩═╯  ╭ ╮╭ ╮    ║   ╭ ║ ║   ╰╮
                                      ╯   ╯ ╯ ╯ 

LONG
        );

        set("exits", ([
		"down": "/u/b/bigcat/room/road8",
        ]) );
setup();

}
