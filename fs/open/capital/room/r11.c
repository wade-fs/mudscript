// Room: /open/capital/room/r11.c

inherit ROOM;

void create ()
{
  set ("short", "環宮大道");
	set( "build", 48 );
  set ("long", @LONG
你現在來到了京城的中央部份, 這兒附近是不準有人逗留的, 偌大
的道路空盪盪的, 映著大紅色的高大宮牆, 別有一份風味, 不過可要小
心別被發現你在閒晃。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/cleanman" : 1,
    "/open/start/npc/handson_du" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r09",
  "east" : __DIR__"r12",
]));
  set("gopath", "east");

  setup();
}
