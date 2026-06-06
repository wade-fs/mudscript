#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
          set("long","洞穴第二層,由於景象都差不多,所以在沒有完整的地圖概念之前,最好不要誤闖此處,旁邊有一個似乎是前人用血寫下來的告示牌(sign)。\n");

        set("exits", ([
          "west":__DIR__"hole12",
          "east":__DIR__"hole11",
          "north":__DIR__"hole24",
          "south":__DIR__"hole21",
      "down":__DIR__"hole2",
        ]) );
        set("item_desc", ([ /* sizeof() == 1 */
        "sign" : "建議您:如果沒有十足的把握的話,最好不要得罪這一樓的mob,我就是死在他們的手上,還有往北,往南的道路有去無回,自己小心!\n"
        ]) );
        setup();
}
