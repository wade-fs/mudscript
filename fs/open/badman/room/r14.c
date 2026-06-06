// Room: /open/badman/room/r14

#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "警備廳辦公室");
  set ("long", @LONG
這裡就是惡人谷人員的調度中心，所有強盜們的行動都由此發
號司令，杜老大的命令也是經由這裡傳達給所有的嘍嘍們知道。你
看到房間裡擺了各式各樣的令旗，還有信號彈等通訊工具。房間的
另一邊放了一些籠子，裡面似乎養著幾隻信鴿的樣子。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r7",
]));
  set("objects", ([
  BAD_NPC"in" : 1,
]));

  set("light_up", 1);

  setup();
}
