inherit ROOM;

void create ()
{
  set ("short", "迴廊");
  set ("long", @LONG
這裡是連接西院和北院的迴廊,在天龍寺中的迴廊都經過精心的設
計,特別拓寬,並在旁邊安置一些花草樹木,布置成為一個適宜修憩的好
地方。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"aa28",
  "south" : __DIR__"aa19",
]));
}
