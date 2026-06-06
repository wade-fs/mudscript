// Room: /open/wu/room/school20
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
這是正晴武館二樓穿堂，四個角落都放置著火把，將房間照得燈火通明，
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/wu/room/school21",
  "north" : "/open/wu/room/school15",
]));
  set("light_up", 1);

  setup();
}
