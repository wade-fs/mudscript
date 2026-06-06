// Room: /u/s/smore/room/suking/suking11+
inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "將軍府二樓");
  set ("long", @LONG
這裡是將軍府的二樓, 也是將軍全家人生活的地方, 向東是
將軍和夫人的寢室, 往下可以回到將軍府. 往將軍寢室有一
道木門, 也許你可以試著打開它(open door).
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : "/open/gsword/room/suking8+",
  "east" : "/open/gsword/room/suking12",
]));
  set("item_desc", ([ /* sizeof() == 1 */
    "east" : (: look_door,     "east" :),
    ]));
  create_door("east", "木雕門", "west", DOOR_CLOSED);
  set("light_up", 1);

  setup();
}
