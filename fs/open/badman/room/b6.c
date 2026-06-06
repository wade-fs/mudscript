// Room: /open/badman/room/b6
inherit ROOM;

void create ()
{
  set ("short", "殿前大道");
  set ("long", @LONG
來到這裡，你突然發現氣氛變得異常凝重，南北兩邊的房間都
有重兵鎮守著，應該是存放著什麼重要物品吧！強烈的好奇心驅使
著你的雙腳不自覺的一步步往前走去，打算看個究竟。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"b7",
  "south" : __DIR__"r8",
  "north" : __DIR__"r10",
  "east" : __DIR__"b5",
]));
  set("outdoors", "/open/badman");

  setup();
}
