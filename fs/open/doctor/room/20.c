#include <room.h>
inherit ROOM;
void create()
{
        set("short","木人場");
        set("long", @LONG

    這裡擺了好幾個木人，木身上面畫滿了人體各大脈門和穴道，學
針灸的最好方法，就是利用這些木人來揣摩實體，看幾個弟子拿支針
在那抸啊抸的，雖然樣子看起來有點矬，不過熟能生巧，往後行醫時
便能準確的認出各大穴位，一旁是華陀的愛徒，正在那細心的指導師
弟們。

LONG
        );

        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 4 */
           "north":__DIR__"16",        
        "south":__DIR__"26",           
        "west":__DIR__"21",           
        "east":__DIR__"19",      

        ]) );
        set("light_up", 1);
        set("objects", ([ /* sizeof() == 2 */
  "/open/doctor/npc/su.c" : 1,
  "/open/doctor/npc/trainee1.c" : 1,
]));

  setup();
}


