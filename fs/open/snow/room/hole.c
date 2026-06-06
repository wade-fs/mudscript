// Room: /open/snow/room/hole.c
// 雪泉聖地中的洞穴
#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG
一個狹小、陰暗、潮濕的洞穴，四周長滿了青苔，看起來好像很久都沒
有人來過的樣子，依靠著從上面透下來些許的光線，隱約的看到有條小
路向前而去。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hole2.c",
  "out" : __DIR__"back",
]));
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
}
