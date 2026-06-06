// Room: /u/l/lotus/f2a.c
inherit ROOM;

void create ()
{
  set ("short", "樓梯口");
  set ("long", @LONG
二樓是小姐們的房間的所在, 東面有一扇大窗, 你可以看到外面
的景色.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"f2b.c",
  "down" : __DIR__"tin4.c",
]));
  set("light_up", 1);

  setup();
}
