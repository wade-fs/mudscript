// Room: /u/f/fire/room/room1-29.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
	set( "build", 12 );
  set ("long", @LONG
從這裡可以更加的清楚的音樂，不只高亢的琴聲，還有釵h旋律
簡單而柔和的鋼琴聲。更令人注意的是在這似乎是跟著這個音樂的節
拍在走動，各各臉上露出一副快樂的表情。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room1-31",
  "south" : __DIR__"room1-27.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/wu-mon.c" : 1,
]));

set("light_up",1);
  setup();
}
