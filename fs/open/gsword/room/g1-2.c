// Room: /open/gsword/room/g1-2.c
inherit ROOM;

void create()
{
  set ("short", "偏廳");
  set ("long", @LONG
這裡是仙劍派的接待廳, 由於掌門已經不管門派的事了, 所以上門
親朋好友, 各派人士, 都必須先經過通報, 在此等候掌門的接見, 為了
不讓客人閒著, 這裡擺了各家的名畫, 當然也缺少不了一些棋子棋盤等
等的東西 .

LONG);

  set("light_up", 1 );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"g1-1",
]) );

  setup();
}
