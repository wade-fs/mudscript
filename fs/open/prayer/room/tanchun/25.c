//open/prayer/room/tanchun/25.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

	天權門的練武場, 練武場上的弟子正在互相套招. 傳聞
	聖火教的聖火奇功乃是專為聖火令所創的武學棍法, 攻
	勢詭異非常, 配合乾坤大挪移的步法, 更能夠巧妙的攻
	擊敵人於無形!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"19",		
        "west":__DIR__"26",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 3 */
	"/open/prayer/npc/trainee1" : 1,	//弟子
	"/open/prayer/npc/trainee4" : 1,	//弟子
	"/open/prayer/npc/man4" : 1,		//教頭   		
]));
     
  setup();
}
