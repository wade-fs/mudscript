// Room: /open/main/room/r42.c

inherit ROOM;

void create ()
{
  set ("short", "平南城近郊");
  set ("long", @LONG
這裡是平南城郊區，平南城就在你的西方，你看到進出平
南城的旅客，有的已不是漢家裝束，你才想起: 這兒已近苗疆
遠離中土，來這裡的人，有的是要回中土，有的則是嚮往那充
滿蠱毒靈藥的苗疆.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"L15",
  "west" : "/open/ping/room/edoor",
  "south" : __DIR__"L23",
  "east" : __DIR__"r43",
]));

  set("outdoors", "/open/main");

  setup();
}
