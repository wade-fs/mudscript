//u/r/rence/room/tanshun/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","議事廳");
        set("long",@LONG

        這裡是議事廳的正中央, 地上鋪著一片深紅色滾邊的地毯
        . 地毯一直延伸到北邊門主的座椅下面, 往南則一直通到
        玄關. 議事廳的四週則站著天璇門內的高職位門徒, 等著
        跟門主報告最新情況.

LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"2",             //議事廳
        "south":__DIR__"8",             //議事廳
        "east":__DIR__"4",              //議事廳
        "west":__DIR__"6",              //議事廳
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
   setup();
}
