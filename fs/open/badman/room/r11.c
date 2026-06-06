// Room: /open/badman/room/r11
inherit ROOM;

void create ()
{
  set ("short", "兵器庫二樓");
  set ("long", @LONG
還沒想到....:b

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"r10",
]));
  set("light_up", 1);

  setup();
}
