// Room: /open/killer/room/ru0.c
inherit ROOM;
void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
這裡是通往黑牙聯總壇大廳的長廊，四周似乎有一些機關，必須要小心一點。
連四周的燭光，似乎也傳來陣陣的殺機，看來這不是一般人該進來的地方。
前方就是傳說中的超級殺手葉秀殺，接見來訪客人的地方。
戒備非常的森嚴，你最好不要輕舉妄動。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ru1.c",
  "down" : __DIR__"floorm.c",
]));
  set("light_up", 10);
  setup();
}
