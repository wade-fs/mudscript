// Room: /u/p/pokai/room/wu/tower5-1
inherit ROOM;

void create ()
{
  set ("short", "武威七殺塔五樓--");
  set ("long", @LONG
來到這裡，你忽然發現地上佈滿一層灰，連剛剛樓梯的把手上，也滿是灰塵，你
想能上到五層樓的人，一定是少之又少。這兒的景色依舊單調：深藍色的牆壁、無窗
格局，唯一令你感到不一樣的，是少了剛剛那一股肅殺之氣。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower5-2",
  "down" : __DIR__"tower4-2",
]));
  set("light_up", 1);

  setup();
}
