// Room: /u/p/pokai/room/wu/tower3-3
inherit ROOM;

void create ()
{
  set ("short", "武威七殺塔三樓--");
  set ("long", @LONG
這裡的陳設和方才的那間相似：空盪盪的，沒有窗戶，只有個往四樓的長梯，
以及一地的血印、破磚、和那股惱人的深藍色，你只覺得自己不斷地在喘氣，彷彿
驚魂未定。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "climb" : __DIR__"tower4-1",
  "west" : __DIR__"tower3-2",
]));
  set("light_up", 1);

  setup();
}
