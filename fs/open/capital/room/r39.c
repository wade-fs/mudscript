// Room: /open/capital/room/r39.c

inherit ROOM;

void create ()
{
  set ("short", "永福胡同");
  set ("long", @LONG
北面有棟頹圮的房子，有幾個混混樣子的人在前面遊蕩，在這種人
稀少的地方遇到這些人還是快溜為妙。也許北邊的那棟房子正是某幫派
的堂口也說不定。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
    "north" : __DIR__"wulaih",
  "west" : __DIR__"r38",
  "east" : __DIR__"r41",
]));
  set("gopath", "west");

  setup();
}
