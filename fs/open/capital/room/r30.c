// Room: /open/capital/room/r30.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
走著走著，人漸漸多了起來，兩邊有一些雜耍的人，旁邊圍了一群
觀眾在鼓掌叫好。原來再往東去就是南市了。北面就是大通驛站，人們
都在那兒傳遞訊息，偶爾換幾匹好馬,繼續向目的地馳去。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"postoffices",
  "west" : __DIR__"r28",
  "east" : __DIR__"r31",
]));
  set("gopath", "west");
  set("gopath2", "west");

  setup();
}
