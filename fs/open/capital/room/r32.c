// Room: /open/capital/room/r32.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
這兒是『南市』的中心。和其它市集相比，這兒算小多了，只有間
小茶館，路邊幾擔賣青菜水果的，幾擔小麵攤子，一些賣姑娘家用的脂
粉的小販，不過還是人擠人，水洩不通。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r31",
  "east" : __DIR__"r33",
]));

  set("gopath", "west");
  set("gopath2", "west");

  setup();
}
