//__DIR__"18.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","總管的書房");
        set("long",@LONG

	玉衡門總管的書房, 書架上放滿著一些關於歷吏方面
        的書籍. 看來總管在閒暇之餘可能對這方面滿有興趣
        你看到一個保鑣正翻著左傳, 聚精會神的閱讀著. 
LONG);

        set("exits", ([ /* sizeof() == 2 */
        "northwest":__DIR__"19",		//總管房
        "north":__DIR__"17",		//總管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/paltoon1" : 1,		//保鑣
   		
]));
     
  setup();
}
