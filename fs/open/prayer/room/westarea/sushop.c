//sushop.c
// made by chun,copy and re-edit by rence
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
  set ("short", "西域市集");
  set ("long", @LONG
  這裡是西域地區唯一的商店,在這你可以估價(value),
賣斷(sell),交易買貨(buy),並可以察看這裡有什麼
貨品待售(list).
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road9",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/keeper" : 1,
]));

  set("light_up", 1);

  setup();
}
