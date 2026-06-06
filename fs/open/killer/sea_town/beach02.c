inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "沙灘");
  set ("long", @LONG
眼前是景色明亮的沙灘，海水清澈，一些螃蟹之類的水中生物都能
看的清清楚楚，遠處有幾個小孩子正在嬉戲玩水，一股平靜的氣息讓你
說不出來的受用!!
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"beach01.c",
  "east" : __DIR__"beach04.c",
  "west" : __DIR__"beach03.c",
  "north" : __DIR__"beach05.c",
]));

  setup();
}
