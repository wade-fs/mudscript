// Room: /open/gsword/room/g3-22.c
inherit ROOM;

void create()
{
  set ("short", "梁發之寢居");
  set ("long", @LONG
這是一間什麼都沒有的房間。
LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"g3-16",
]) );

  setup();
}
