// Room: /open/capital/room/r62.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
  set ("long", @LONG
北邊是城內首富乾通天的宅地，住在旁邊的是當今的丞相，由於兩
人與鎮遠侯不合，所以分開兩邊住。仔細的往北瞧, 裡頭似乎是一座相
當優美的花園, 空氣中還傳來陣陣花香味。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"rich",
  "west" : __DIR__"r60",
  "east" : __DIR__"r63",
]));
  set("outdoors", "/open/capital");

  setup();
}
