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

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room2-5",
  "east" : __DIR__"room2-3",
]));
  set("outdoors", "/open/marksman");

  setup();
}
