inherit ROOM;

void create ()
{
  set ("short", "南堂風");
  set ("long", @LONG
不知道是不是迷信的關係，總覺得有一道冷風從背脊游走過，身
體不自然的顫抖著，難道是這裡有怪東西嗎？但是除了書本以外，再
也沒有其它奇怪的東西了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wind",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_wind.c" : 1,
]));

  setup();
}
