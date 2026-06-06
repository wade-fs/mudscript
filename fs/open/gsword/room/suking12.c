// Room: /u/s/smore/room/suking/suking12.c

inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "將軍寢室");
	set( "build", 72 );
  set ("long", @LONG
    你走進了一間普普通通的房間, 既沒有欄雕玉砌,也沒有珠
寶珍藏,蜀中將軍的居所竟是如此的簡簡單單, 然而平淡的擺設
中,卻不失其高雅.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/suking11+",
]));
   set("item_desc", ([ /* sizeof() == 1 */
       "west" : (: look_door,     "west" :),
        ]));
  create_door("west", "木雕門", "east", DOOR_CLOSED);
  set("objects",([
      "/open/gsword/mob/z_wife":1,
      ]));
  set("light_up", 1);

  setup();
}
