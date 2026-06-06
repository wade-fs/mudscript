// Room: /open/killer/room/ru2.c
inherit ROOM;
void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
這裡是通往黑牙聯總壇大廳的長廊，四周似乎有一些機關，必須要小心一點。
連四周的燭光，似乎也傳來陣陣的殺機，看來這不是一般人該進來的地方。
前方就是傳說中的超級殺手葉秀殺，接見來訪客人的地方。
東方通往的是殺手專用的兵器室，殺手需要的武器可以在那裡取得。
但是，那裡據說有東洋機關手諸岡渡，所設計的機關存在，只有殺手知道如何通過。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ru3.c",
  "south" : __DIR__"ru0.c",
  "east" : __DIR__"ru2.c",
  "west" : __DIR__"bankrm.c",
]));
  set("light_up", 10);
  setup();
}
