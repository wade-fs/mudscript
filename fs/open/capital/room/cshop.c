// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
  set ("short", "乾記商行");
  set ("long", @LONG
一進到這裡就被那富麗堂皇的裝設所鎮攝，其裝潢之華麗，與一般
之小店鋪截然不同，這家商行是城內首富乾通天的產業之一，不過最近
他已經很少來此，這裡的問題全部交給總管卜士仁負責打點。在右邊的
牆上掛了個告示(note)。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "note" : "
	< value > : 估價
	< list >  : 列出
        < buy  >  : 買
	< sell >  : 賣出
 ",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"h09.c",
]));
  set("light_up", 1);

  setup();
}
