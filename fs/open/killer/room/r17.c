// Room: /open/killer/room/r17.c
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
這裡是黑牙聯總壇的長廊，四周似乎有一些機關，必須要小心一點。
連四周的燭光，似乎也傳來陣陣的殺機，看來這不是一般人該進來的地方。
令你有一點打退堂鼓了，看來還是外面的氣氛好一點。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"floorm.c",
  "out" : __DIR__"doorm.c",
]));
  set("light_up", 10);
  setup();
}
