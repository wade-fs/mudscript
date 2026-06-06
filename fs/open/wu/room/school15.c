// Room: /open/wu/room/school15
inherit ROOM;

void create ()
{
  set ("short", "正晴武館二樓");
  set ("long", @LONG
這是正晴武館二樓穿堂，四個角落都放置著火把，將房間照得燈火通明，
北，東，南各有一個通道，通往任正晴兒女的房間
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/wu/room/school20",
  "north" : "/open/wu/room/school18",
  "east" : "/open/wu/room/school16",
  "westdown" : "/open/wu/room/school8",
]));

  set("light_up", 1);
  setup();
}
