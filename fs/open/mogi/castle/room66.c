inherit ROOM;
#include <ansi.h>
#include "castle.h"
void create ()
{
  set ("short", "鎖仙室");
	set( "build", 25 );
  set ("long", @LONG
甫進此房間，你就感到一股魔氣襲人，纏繞得你渾身不舒服。看來這裡
就是焚天魔王用來拘禁風青雲的所在，在這種地方待越久，身上就會沾
染越多魔氣，終至魔氣矇心，本性全失。
LONG);

  set("evil", 1);
  set("no_auc", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yan" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room64",
//  "up" : "/open/god/sky/sky_start.c",
]));
  set("no_transmit", 1);

  setup();
}
