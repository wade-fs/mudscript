inherit ROOM;

void create ()
{
  set ("short", "西堂土");
  set ("long", @LONG
不知是不是迷信的關係，總覺得呼吸困難的，汗流不止，難道是
緊張的原因，總覺得是從書籍發散過來的，這裡的書本可真奇妙呀，
還是只是巧合。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"land.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_land.c" : 1,
]));

  setup();
}
