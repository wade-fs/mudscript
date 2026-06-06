#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "玄關");
  set ("long", @LONG
後堂到了這兒有個轉角, 通向一間房間去, 角落處擺設著一瓶花
, 連著掛著幾幅詩畫, 一看之下似乎出自名家之手, 頗有一種非凡之
勢。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"np27",
  "west" : __DIR__"np22",
]));
  set("light_up", 1);

  setup();
}
