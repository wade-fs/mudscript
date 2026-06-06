 // 增加npc doctor01 06/13/93 by firedancer

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "木人場");
        set("long", @LONG

    這裡擺了好幾個木人，木身上面畫滿了人體各大脈門和穴道，學
針灸的最好方法，就是利用這些木人來揣摩實體，看幾個弟子拿支針
在那抸啊抸的，雖然樣子看起來有點矬，不過熟能生巧，往後行醫時
便能準確的認出各大穴位。

LONG
        );

        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"21",
        "east":__DIR__"26",

        ]) );
        set("objects",([
"/open/area/house/npc/doctor01":1,
]));
      
  setup();
}

