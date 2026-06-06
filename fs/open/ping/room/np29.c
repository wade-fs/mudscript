#include "/open/open.h"
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "寢居");
  set ("long", @LONG
你走進此房, 感覺眼睛一亮 ,四周打掃的很乾淨, 簡直就像是新的
一般, 這正是段雲愛女～段小詩～的閨房, 若說有何突兀的地方, 大概
是牆上掛著一些筆、扇等書生專用的兵器。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"np28",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan0" : 1,
]));

  setup();
}
