// Room: /open/poison/room/path1.c
inherit ROOM;

void create ()
{
  set ("short", "密道");
  set ("long", @LONG
    這裡是冥蠱魔教新建的聯外密道，兩旁盡是熊熊火
炷，整個密道隴照在一片火紅的光芒中。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"path2",
  "east" : __DIR__"room2",
]));
  set("light_up", 1);

  setup();
}
