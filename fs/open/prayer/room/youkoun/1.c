//open/prayer/room/youkoun/1.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","瑤光門大廳");
        set("long",@LONG

        在大廳的東方站著一位右護法, 專職保護門主的工作. 往
        東則是練功房. 如果你是聖火教徒, 可以隨時進去裡面練
        習.

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"4",         //大廳
        "west":__DIR__"2",              //門主
        "east":__DIR__"28",
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/right7" : 1,          //右護法
]));
  setup();
}

int valid_leave(object me, string dir)
  {
  if(dir=="east" && me->query("class") != "prayer")
        return notify_fail("不是教徒是不能進入的 !\n");
        
        return ::valid_leave(me,dir);
}

