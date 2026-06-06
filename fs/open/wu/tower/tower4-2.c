// Room: /u/p/pokai/room/wu/tower4-2
inherit ROOM;

void create()
{
  set ("short", "武威七殺塔四樓--");
  set ("long", @LONG
你眼前有一個大梯子，你想又是往上推進一樓的時刻了。由於疲累的關係，你對
四週的景致也無心注意，你只覺得四週的暗藍色比剛剛的都還要來得深、也還要來沈
。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "climb" : __DIR__"tower5-1",
  "north" : __DIR__"tower4-1",
]));
  setup();
}
