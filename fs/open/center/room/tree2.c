// Room: /u/l/lotus/girl/tree2
#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "前院");
  set ("long", @LONG
院中有一棵大榕樹, 客人們的轎子就停在樹下. 各式各樣的大轎
子, 從普通的到華麗的, 可想而知這裡三教九流的人都有. 院子四周
種滿了茶花, 開得相當好看.
LONG);

  set("light_up", 1);
  set("outdoors", "/u/l/lotus/girl");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tree.c",
  "south" : __DIR__"men.c",
]));

  setup();
}
