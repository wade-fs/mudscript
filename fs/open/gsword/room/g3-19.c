// Room: /open/gsword/room/g3-19.c
inherit ROOM;

void create()
{
  set ("short", "張乘雲之寢居");
  set ("long", @LONG
這是一間什麼都沒有的房間。
LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"g3-17",
]) );

  setup();
}
