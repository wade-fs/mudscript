// Room: /open/soulin/room/s05.c

inherit ROOM;

void create ()
{
  set ("short", "少林寺前廣場");
  set ("long", @LONG

這裡是少林弟子們練功的場所，四周擺滿了練功的器具。北邊有個穿堂
可進入寺中。

LONG);

  set("outdoors", "/open/soulin");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"s41",
  "east" : __DIR__"s06",
  "west" : __DIR__"s04",
  "south" : __DIR__"s02",
]));

  setup();
}
