//open/prayer/room/tanshun/18.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",@LONG

        走廊的廊頂是使用上等的西域檜木建造的, 隨時都會散發
        出特有的檜木香. 東邊是練武場, 順著走廊則可以到達總
        管的書房. 不過總管好像不怎麼歡迎男性..

LONG);

        set("outdoors", "/open/prayer/room");
        set("no_fight", 0);
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"17",             //走廊
        "south":__DIR__"23",            //走廊
 
        ]) );
        
  setup();
}

int valid_leave(object me, string dir)
  {
    if(dir=="south"&&me->query("gender")=="男性")
        return notify_fail("男人是無法進入總管書房的 ?\n");
        
   return 1;
}
