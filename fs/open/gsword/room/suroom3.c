// Room: /open/gsword/room/suroom3.c

inherit ROOM;

void create ()
{
  set ("short", "富商家");
  set ("long", @LONG
這是一間什麼也沒有的空房間。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room/su12",
]));

  set("light_up", 1);

  setup();
}
