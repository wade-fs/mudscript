// Room: /u/w/whatup/poison_hole/room11.c
inherit ROOM;

void create ()
{
  set ("short", "小山坡");
  set ("long", @LONG
這裡一條小路漸漸的往上爬，雖然不陡，但走起來也讓人氣喘如牛
，這樣的路不知道到哪才有盡頭。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room11.c",
  "up" : __DIR__"room14.c",
]));
  set("outdoors", "/u/w");

  setup();
}
