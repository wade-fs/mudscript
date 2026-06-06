//open/prayer/room/youkoun/8.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副門主房");
        set("long",@LONG

        在辦公房的南邊, 副門主正在跟她最信任的女弟子討論門
        內的事務. 看她們一副拿不定主意的樣子, 令你不禁想上
        前去提供意見.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"7",             //副門主室
        "northeast":__DIR__"5",         
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/vice-chair7" : 1,             
        "/open/prayer/npc/trainee3" : 1,                //弟子
                
]));
     
  setup();
}
