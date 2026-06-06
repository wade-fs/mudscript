#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "蒙古草原");
  set ("long", @LONG
  東邊的草地上坐落著幾頂蒙古包，拆卸以及裝設都可以在短時間內
完成，是遊牧民族賴以維生的住所。獸皮製成，配合樹幹搭建，提供
家人與牲畜遮風避雨的地方。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"grass17.c",
  "east" : __DIR__"shack6.c",
  "north" : __DIR__"grass20.c",
  "south" : __DIR__"grass13.c",
]));
  set("outdoors", 1);

  setup();
}
