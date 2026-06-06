inherit ROOM;

void create ()
{
  set ("short", "南堂火");
  set ("long", @LONG
不知是不是迷信的關係，總覺得有聞到焦烤的味道，難道書本燒
起來了，還是只是自己的多慮，是那些書讓我有這種想法的嗎？這裡
的書本可真奇妙。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"fire.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_fire.c" : 1,
]));

  setup();
}
