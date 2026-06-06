// Room: /open/capital/room/r38.c

inherit ROOM;

void create ()
{
  set ("short", "永福胡同");
  set ("long", @LONG
遠遠得看到斜坡的盡頭。這裡比較冷清，沒有店家在這開業，所以
人煙稀少，也因為人少，石板路旁都長滿了雜草而無人理會。從這兒可
以看到大部份的京城。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/walker1" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r36",
  "east" : __DIR__"r39",
]));
  set("gopath", "west");

  setup();
}
