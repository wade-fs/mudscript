// Room: /open/ping/room/p7
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "寢居");
  set ("long", @LONG
這裡是一間整齊的房間, 四周打掃的很乾淨, 簡直就像是新的一般
, 你看到這裡的擺設似乎是一位女孩子家的房間, 若說有何突兀的地方
大概是牆上掛著一些筆、扇等書生專用的兵器。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p6",
]));
  set("objects", ([ /* sizeof() == 1 */
  PING_NPC"duan0" : 1
]));
  set("light_up", 1);

  setup();
}
