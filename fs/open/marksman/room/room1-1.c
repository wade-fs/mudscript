// Room: /u/f/fire/room/room1-1.c
#include <ansi.h>
#include "marksman.h"
inherit ROOM;

void create ()
{
  set ("short", "長沙城");
  set ("long", @LONG
長沙城乃李廣大人所生長的地方，那裏人人受惠無窮，富甲一方
。在長沙城的居民住著安居樂業，平平安安的城鎮，充滿了一股安寧
和諧的氣象。你看到一群全副武裝的守衛正在顧守自己的岡位上守護
著以防外人攻擊。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2-5",
  "north" : __DIR__"room1-2.c",
]));
set("outdoors","/open/marksman");

  setup();
}
