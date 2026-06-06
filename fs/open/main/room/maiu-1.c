// Room: /open/main/room/maiu-1.c
inherit ROOM;

void create ()
{
  set ("short", "瀾蒼江畔");
	set( "build", 78 );
  set ("long", @LONG

這裡是瀾滄江畔的陡崖,瀾滄江就在你腳下的深谷裡  ◇◆───────┐
,往下一望,只見江水滔滔,非但赤腳難以涉水走過,   ◆                │
就是行舟,也未必渡得過這滔天江水,你西邊有一座   │    西域往北    │
吊橋,高高的橫過江面.                           │                ◆
  往北走通往〔西域〕                           └────歧路人◆◇

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/prayer/room/westarea/road37",
  "east" : __DIR__"r41",
  "south" : __DIR__"to_chun1.c",
  "west" : __DIR__"maiu-2",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/murofu" : 1,
]));
  set("資源", ([ /* sizeof() == 1 */
  "液體" : ([ /* sizeof() == 3 */
      "止渴" : 30,
      "名稱" : "清水",
      "種類" : "水",
    ]),
]));
  set("outdoors", "/open/ping");

  setup();
}
