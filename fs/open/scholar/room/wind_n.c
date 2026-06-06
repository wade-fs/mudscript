inherit ROOM;

void create ()
{
  set ("short", "北堂風");
  set ("long", @LONG
不知道是不是迷信的關係，總覺得有股涼風往臉上吹來，奇怪的
是，四周都是密壁不應該有風會吹進來，這裡除了書本以外，沒有其
它的了，還是自己太神經質了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wind.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_wind.c" : 1,
]));

  setup();
}
