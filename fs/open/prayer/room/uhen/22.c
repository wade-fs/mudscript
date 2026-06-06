//open/prayer/room/uhen/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        你看到練武場上的二名弟子正在練武場上跑來跑去.  
        腳上似乎還綁著相當沉重的鉛塊來訓練腳力. 看來門 
        主對於腿力相當的重視.
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"15",		
        "east":__DIR__"21",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,		//弟子
        "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
