inherit ROOM;

void create()
{
  set ("short", "庭院門口");
  set ("long", @LONG
庭院門口有人在看守。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"camp10.c",
    "south" : __DIR__"camp08.c",
  ]));
  setup();
}
