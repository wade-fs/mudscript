// Room: /open/badman/room/t5.c

inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG
前頭似乎有一點光線，不知道是不是出口快到了，你不禁加快
了腳步，想早一點離開這個令人作嘔的地道。這裡的空間好像比剛
才寬敞了一點，顯得比較好走。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/badman/room/t4",
  "north" : "/open/badman/room/t6",
]));

  setup();
}
