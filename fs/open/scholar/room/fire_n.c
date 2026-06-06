inherit ROOM;

void create ()
{
  set ("short", "北堂火");
  set ("long", @LONG
不知是不是迷信的關係，總覺得臉上有著燙燙的感覺，難道是緊
張的原因，好像是從書籍發散過來的，這裡的書本可真奇妙呀，還是
只是巧合。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"fire.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_fire.c" : 1,
]));

  setup();
}
