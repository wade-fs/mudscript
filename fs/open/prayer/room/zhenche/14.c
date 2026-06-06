//open/prayer/room/zhenche/14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","走廊");
        set("long",@LONG

        走廊的廊頂是使用上等的西域檜木建造的, 隨時都會散發
        出特有的檜木香. 西邊是練武場, 順著走廊則可以到達副
        門主的辦公房. 不過副門主好像不歡迎女性..

LONG);

        set("outdoors", "/open/prayer/room");
        set("no_fight", 0);
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"12",             //走廊
        "west":__DIR__"15",             //走廊
 
        ]) );
        
  setup();
}

int valid_leave(object me, string dir)
  {
    if(dir=="east"&&me->query("gender")=="女性")
        return notify_fail("女人是無法進入副門主的辦公房的 !\n");
        
   return 1;
}

