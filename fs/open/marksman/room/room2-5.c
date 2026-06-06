// Room: /open/marksman/room/room2-4
inherit ROOM;

void create ()
{
  set ("short", "石板小道");
  set ("long", @LONG
一條用石板所鋪設完成的小道，這裡的人跡似乎
    越來越多的現象，往遠處一看，好像有個鎮
    在遠處。
LONG);

  set("outdoors", "/open/marksman");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room1-1",
  "north" : __DIR__"room2-4",
  "south" : "/open/scholar/room/newplan/area/f1.c",
]));

  setup();
}
