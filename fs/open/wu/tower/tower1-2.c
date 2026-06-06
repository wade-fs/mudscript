// Room: /u/p/pokai/room/wu/tower1-2
inherit ROOM;

void create ()
{
  set ("short", "武威七殺塔一樓--");
  set ("long", @LONG
來到這裡，你發現殺氣越來越濃，由於緊張的關係。四周的景緻你也無心看顧，
只覺得映入眼廉的是一片片的暗紅色，你不禁感到有些頭暈。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower1-1",
  "east" : __DIR__"tower1-3",
]));
  set("light_up", 1);

  setup();
}
