// Room: /open/capital/room/r46.c

inherit ROOM;

void create ()
{
  set ("short", "日升馳道");
  set ("long", @LONG
西邊有個小廣場，廣場上有幾間小茅草屋。屋旁擺了一些農具，看
起來似乎是處理糧草用的。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/capital/room/farm",
  "south" : "/open/capital/room/r45",
  "north" : "/open/capital/room/r47",
]));

  set("gopath", "south");

  setup();
}
