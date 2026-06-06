// Room: /open/badman/room/r12
inherit ROOM;

void create ()
{
  set ("short", "武道館內廳");
  set ("long", @LONG
來到這裡，你馬上感到一股嚴肅的氣氛，外面大廳的吵雜聲似
乎也完全被掩蓋了過去。四面的牆上裝飾著各式各樣的奇珍異寶，
但是都抵不過你正前方的牆上所掛著的大獅頭來的引人注目。你看
到房間的中央放了一張獅皮裝飾的大椅。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r6",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/te" : 1,
]));
  set("light_up", 1);

  setup();
}
