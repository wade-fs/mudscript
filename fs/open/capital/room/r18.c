// Room: /open/capital/room/r18.c

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG
往北是威西門，在右手邊有一堵綿延很長的高牆，漆成很亮的赤紅
色，牆頂還有金黃色的琉璃瓦，相當氣派。你猜想這不知道是那戶大戶
人家的豪邸。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r16",
  "south" : __DIR__"r19",
  "east" : __DIR__"ke1.c",
]));
  set("gopath", "north");

  setup();
}
