//__DIR__"15.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        你看到練武場上的兩名弟子身形忽左忽右. 原來是
        在練習聖火教的另一高深武學乾坤大挪移. 不過這
        兩名弟子似乎還不是很純熟的樣子. 有時竟會撞在
        一起.
        西邊是總管的書房. 如果你是男生的話. 最好能知
        難而退. 
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"14",		
	"south":__DIR__"22",		//練武場
	"west":__DIR__"17",	
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,		//弟子
        "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
 int valid_leave(object me, string dir)
  {
    if(dir=="west"&&me->query("gender")=="男性")
        return notify_fail("男人是無法進入總管的辦公房的 ?\n");
        
   return 1;
}
