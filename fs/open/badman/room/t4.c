// Room: /open/badman/room/t4.c

inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG
通過了藤蔓背後的通道以後，你來到了地道的另一端，這裡完
全沒有剛剛那些藤蔓的存在，可見那些藤蔓是有人為了不被人發現
而刻意弄出來的吧，或許這裡是通往某個地方的祕密通道也說不一
定。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/badman/room/t5",
  "east" : "/open/badman/room/t3",
]));

  setup();
}
