inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "狂風七星陣陣心");
  set ("long", @LONG

    你走進這裡, 突然一陣狂風吹起, 括起漫天風沙, 你置
身在這疾風當中, 頓感一陣暈炫, 眼前一片模糊, 看不清出
四周的事物。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "leave" : "/open/main/room/maiu-1.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/m-ya" : 1,
]));
  set("no_transmit", 1);

  setup();
  replace_program(ROOM);
}
