// Room: /u/f/fire/room/room1-25.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
  set ("long", @LONG
令人感覺氣勢非凡的將軍府，圍牆上飄揚著紅色的旗幟，大門兩
旁站著身穿藍色披風、潔白的鎧甲、戴著厚重的頭盔，威武十足的武
士。釵h高雅的侍女正來來往往的。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-23",
  "north" : __DIR__"room1-27.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman" : 2,
]));

  setup();
}
