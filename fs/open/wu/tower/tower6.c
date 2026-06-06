// Room: /u/p/pokai/room/wu/tower6
inherit ROOM;

void create ()
{
  set ("short", "武威七殺塔六樓--");
  set ("long", @LONG
這裡幾乎快到頂層。你來到了是武威七殺塔的到數第二層，你感覺這樓比剛剛素
淨，房間的角落有一個老人站在那兒，對這窗子外面的景色嘆息。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower7",
  "down" : __DIR__"tower5-2",
]));
  set("light_up", 1);

  setup();
}
