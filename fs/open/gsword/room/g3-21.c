// Room: /open/gsword/room/g3-21.c
inherit ROOM;

void create()
{
  set ("short", "趙鶴之寢居");
  set ("long", @LONG
這是一間什麼都沒有的房間。
LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"g3-16",
]) );

  setup();
}
