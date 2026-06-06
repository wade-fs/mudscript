// Room: /u/w/whatup/poison_hole/room11.c
inherit ROOM;

void create ()
{
  set ("short", "小山坡");
  set ("long", @LONG
這裡一條小路漸漸的往上爬，雖然不陡，但走起來也讓人氣喘如牛
，這樣的路不知道到哪才有盡頭。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room18.c",
  "down" : __DIR__"room15.c",
  "east" : __DIR__"room19.c",
  "north" : __DIR__"room20.c",
]));
  set("outdoors", "/u/w");

  setup();
}
