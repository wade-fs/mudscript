#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "蒙古草原");
  set ("long", @LONG
這裡是蒙古大草原的邊陲，往南、北、西三個方向望去，視線所及，
全是一望無際的遼闊草原，草地上到處散布著游牧民族的蒙古包以及牲畜
的身影。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"grass22.c",
  "eastdown" : __DIR__"slope04",
]));
  set("outdoors", 1);

  setup();
}
