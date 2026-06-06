inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIW + "狂風七星陣" + NOR);
  set ("long", @LONG

    你走進這裡, 突然一陣狂風吹起, 括起漫天風沙, 你置
身在這疾風當中, 頓感一陣暈炫, 眼前似乎有幾盞燈火, 指
引你走出此地。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "leave" : "/open/main/room/maiu-1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hu" : 1,
]));
  set("light_up", 1);
  set("no_transmit",1);

  setup();
}
