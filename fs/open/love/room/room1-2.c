inherit ROOM;

void create ()
{
  set ("short","走廊");
  set ("long", @LONG
這是絕情門的主要通路，二旁是花園，往北一直走到底，你將會
看到一座籠罩著殺氣的房子，令你有種想要回頭的感覺，因為你
在這是不受歡迎的人，所有的人都想要致你於死地，你現在想回
頭但已太遲，你要為自已的自大付出代價。
LONG);
  set("objects", ([ /* sizeof() == 1 */
"/open/love/npc/hero":2,
  ]));
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room1-3",
  "east" : __DIR__"room2-11",
  "west" : __DIR__"room2-10",
  "south" : __DIR__"room1-1",
  ]));
  set("light_up", 1);

  setup();
}

