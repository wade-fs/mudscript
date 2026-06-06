// Room: /open/capital/room/r37.c

inherit ROOM;

void create ()
{
  set ("short", "永福胡同");
  set ("long", @LONG
遠遠得看到斜坡的盡頭。這裡比較冷清，沒有店家在這開業，所以
人煙稀少，也因為人少，石板路旁都長滿了雜草而無人理會。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r36",
  "east" : __DIR__"r38",
]));

  set("gopath", "west");

  setup();
}
