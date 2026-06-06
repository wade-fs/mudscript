//open/prayer/room/tanchun/30.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練功\房");
        set("long",@LONG

	天權門私設的練功房, 裡頭有鐵鼎與許多的石碑. 這裡是司徒榮親
	傳其家傳武學的地方!!那一座石人是專門輔助練功用的!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 1 */
	"south":__DIR__"2",		//門主
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/teststone" : 1,		//石人
   		
]));
     
  setup();
}

