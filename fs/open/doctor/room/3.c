#include <room.h>
inherit ROOM;
void create()
{
        set("short","銀針門偏廳");
        set("long", @LONG

    角落那裡擺了一張石几和幾張石椅，華陀的徒弟正坐在那為師父
磨針，旁邊是一排白鶴圖樣的木製屏風，後面是一張木床，那是華陀
給人開膛剖腹用的，也就是所謂的手術間了。

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"2",     
        "south":__DIR__"6",
        "west":__DIR__"29",

        ]) );
        set("light_up", 1);
        set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/npc/liu" : 1,
]));
  setup();
}



