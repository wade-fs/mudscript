//__DIR__"13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG
         
        你看到練武場上兩個弟子正互相在切磋武技, 雙方你來我往
        頓時拳腳滿天飛. 不過旁邊的東西也被打壞不少...
        西邊是往副門主的辦公房.
 
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
