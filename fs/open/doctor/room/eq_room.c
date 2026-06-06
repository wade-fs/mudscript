// Room: /open/doctor/room/eq_room.c made by adam..


inherit ROOM;

void create ()
{
  set ("short", "大夫休息室");
  set ("long", @LONG

進到這裡，你可以盡情的休息。對於剛作完整日醫療的你，
這裡是你最好的休息場所。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"2",
]));

  set("no_fight", 1);

  set("light_up", 1);
  set("no_magic", 1);

  setup();
}


