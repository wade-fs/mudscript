//__DIR__"19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	玉衡門總管的書房, 這裡是總管處理門務的地方. 你
        看到總管剛將文件放下準備起身. 大概是己處理完所
        有的文件準備去休息室休息了吧. 

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northeast":__DIR__"16",		//總管房
        "southeast":__DIR__"18",		//總管房
        "east":__DIR__"17",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-manager" : 1,		//總管
   		
]));
     
  setup();
}
