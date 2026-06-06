// open/killer/ninja/find/r1.c
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG

     如夢似幻之間，你來到了一個奇怪的空間，環顧四週，似乎非常熟悉？
     這裡好像是冥蠱魔教附近的山上，你怎麼會來到這裡呢？
     前面有一個人慌慌張張的逃出，似乎身受重傷，你定睛一看，他居然是柴榮？!
     但是又出乎你意料之外的年輕？莫非你真的來到了十幾年前？
     為了避免犯下嚴重錯誤，還是小心的跟蹤會比較好一點......

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "跟蹤" : "渾沌的過去....必須要自己去探索",
                   ]));
                   
  set("exits", ([ /* sizeof() == 3   */
     "跟蹤" : __DIR__"r2.c",   
]));
  setup();
}
