// Room: /u/l/lotus/girl/f2b.c
inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
掛了兩盞明晃晃的花燈, 煞是好看. 東面有一扇大窗, 你可以看
到外面的景色.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"f2c.c",
  "east" : __DIR__"f2a.c",
]));
  set("light_up", 1);

  setup();
}
