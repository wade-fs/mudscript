// Room: /u/p/pokai/room/wu/tower5-2
inherit ROOM;

void create ()
{
  set ("short", "武威七殺塔五樓--");
  set ("long", @LONG
你發現這兒的景緻忽然一變，強烈的白色映入你眼簾，你注意到這裡有一個紅木
窗櫺的窗子，屋子中央還有一個大大的蒲團，蒲團上安坐著一個老人。你看到通往六
樓的梯子近在咫尺，不禁有一股衝動想趕快上去！你注意到牆角有一堆枯骨。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tower5-1",
  "climb" : __DIR__"tower6",
]));
  set("light_up", 1);

  setup();
}
