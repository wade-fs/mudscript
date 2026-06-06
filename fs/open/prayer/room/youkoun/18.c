//open/prayer/room/youkoun/18.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","練武場");
        set("long",@LONG

        在練武場的西方, 有兩個女弟子正在整理衣裳, 準備隨時
        下場示範另一段的動作. 看來功夫應該也不弱才對! 令你
        不禁想找她們先行較量一番..

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"11",            //練武場
        "south":__DIR__"21",            //練武場
        "east":__DIR__"17",             //練武場
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee4" : 1,                //弟子
        "/open/prayer/npc/trainee4" : 1,                //弟子
                
]));
     
  setup();
}
