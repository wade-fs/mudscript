#include "/open/open.h"
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "寢居");
  set ("long", @LONG
這裡是三師兄段遠風的住處, 裡頭有床椅等家具, 佈置的溫暖舒
適牆上掛了許多精美的字畫, 都是段遠風的手筆, 你不禁欽佩他文武
全才。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"np14",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan3.c" : 1,
]));

  setup();
}
