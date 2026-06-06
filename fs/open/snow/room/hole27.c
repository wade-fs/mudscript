#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG
看到從第一層傳到這裡的光線,有點向柳暗花明又一村的感覺,經歷這樣長時間在伸手不見五指的環境下,現在的你只想趕快往下離開。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hole26",
]));

  setup();
}
