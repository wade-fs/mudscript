//__DIR__"11.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

	玉衡門副門主的辦公房. 西邊是通往練武場的方向,
	南邊是往副門主的書房. 你看到兩個身材高大的聖火
        教弟子站在門口守衛. 而房內的擺設看來相當華麗.

LONG);

        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"10",		//副門主室
	"south":__DIR__"12",		//副門主室
	"west":__DIR__"13",		//走廊
        "east":__DIR__"9",		//副門主室
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,		//弟子
        "/open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
