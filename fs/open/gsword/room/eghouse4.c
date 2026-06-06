// Room: /open/gsword/room/eghouse4.c
inherit ROOM;

void create()
{
  set ("short", "大師兄的寢居");
  set ("long", @LONG
這是仙劍派大師兄的寢居，左邊是一張寒玉所造的石床，
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eghouse3",
]) );

  setup();
}
