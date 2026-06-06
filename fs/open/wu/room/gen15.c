inherit ROOM;
#include <ansi.h>
void create ()
{
  seteuid(getuid());    // 不是說要加這一行嗎?
        set("short",HIC"-八卦迷宮-"NOR);
        set("long", @LONG
虛幻漂渺你不知身在何方，眼前竟是各種太極圖形漂浮在你面前。乾卦
、坤卦、兌卦、震卦..等圖形如有生命般從你前面漂浮!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "乾卦" : "/open/wu/room/gen11",
  "坤卦" : "/open/wu/room/gen16",
  "兌卦" : "/open/wu/room/gen13",
  "震卦" : "/open/wu/room/gen9",
]));
  set("no_transmit",1);
  set("no_auc",1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/corpse2" : 4,
]));
  setup();
}
