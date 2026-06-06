// Room: /open/gsword/room/g3-18.c
inherit ROOM;

void create()
{
  set ("short", "張乘風之寢居");
  set ("long", @LONG
這是一間什麼都沒有的房間。
LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"g3-17",
]) );

  setup();
}
