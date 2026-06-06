// Room: /open/ping/room/p4
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "寢居");
  set ("long", @LONG
這裡是段王府裡的東邊廂房, 裡頭有床椅等家具, 佈置的溫暖舒適
地上都打掃的乾乾淨淨的, 令人感到十分溫馨。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p3",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan7" : 1,
]));

  setup();
}
