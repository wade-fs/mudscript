// Room: /open/badman/room/b4
inherit ROOM;

void create ()
{
  set ("short", "十字路口");
  set ("long", @LONG
你走到了一個十字路口，兩條街道各自往南北兩方延伸下去。
往西可直接通往惡人谷主的大殿，不過一路上似乎戒備森嚴的樣子
，還是別亂闖的好。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"b5",
  "north" : __DIR__"b8",
  "south" : __DIR__"b14",
  "east" : __DIR__"b3",
]));
  set("outdoors", "/open/badman");

  setup();
}
