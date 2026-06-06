inherit ROOM;

void create ()
{
  set ("short", "東堂火");
  set ("long", @LONG
不知是不是迷信的關係，總覺得這裡的空氣又悶又熱，難道是緊
張的原因，總覺得是從書籍發散過來的，這裡的書本可真奇妙呀，還
是只是巧合。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fire.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_fire.c" : 1,
]));

  setup();
}
