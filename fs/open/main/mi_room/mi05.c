inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIR + "狂風七星陣" + NOR);
  set ("long", @LONG

    你走進這裡, 突然一陣狂風吹起, 括起漫天風沙, 你置
身在這疾風當中, 頓感一陣暈炫, 眼前似乎有幾盞燈火, 指
引你走出此地。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "天樞" : "/open/main/room/maiu-1.c",
  "天權" : __DIR__"mi_dead.c",
  "天璣" : __DIR__"mi_dead.c",
  "玉衡" : __DIR__"mi06.c",
  "開陽" : __DIR__"mi_dead.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/killer" : 2,
]));
  set("light_up", 1);
  set("no_transmit",1);

  setup();
}
