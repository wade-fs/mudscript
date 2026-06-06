//open/prayer/room/kiyan/13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	開陽門的練武場, 練武場上的弟子正在訓練腿力. 傳聞聖火教的武
	學共有三套, 第三便是乾坤大挪移的步法, 是教主由東土所習得的
	武學!!能夠巧妙的避開敵人的攻擊!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"11",		//走廊
	"south":__DIR__"20",		//練武場
	"west":__DIR__"14",		//練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}

 int valid_leave(object me, string dir)
  {
    if(dir=="east"&&me->query("gender")=="女性")
        return notify_fail("女人是無法進入副門主的辦公房的 !\n");
        
   return 1;
}
