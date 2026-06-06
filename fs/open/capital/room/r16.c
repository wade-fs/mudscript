// Room: /open/capital/room/r16.c

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG
你走在兩座高牆之間，左邊的是有四五層樓高的灰色大石牆，保衛
著京城的安全，右邊是鎮遠侯府的紅色牆，也有三層樓那麼高，不禁想
起自己的窩只是間爛茅草屋。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/capital/room/r18",
  "north" : "/open/capital/room/r02",
]));

  set("gopath", "north");

  setup();
}
