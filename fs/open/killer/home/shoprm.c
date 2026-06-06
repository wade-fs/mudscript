// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
  set ("short", "二手貨專賣處");
  set ("long", @LONG
  這裡是殺手們交換二手貨的好地方,在這你可以估價(value),賣斷(sell),
  交易買貨(buy),並可以察看這裡有什麼貨品待售(list).
  採自由販賣式，所以沒有老闆，但是有人在暗中監視，以免二手貨失蹤。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r18.c",
]));

  set("light_up", 1);

  setup();
}
