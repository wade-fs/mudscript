// room:open/doctor/room/d7.c made by adam..

inherit ROOM;

void create ()
{
	set("short","走廊");
  set ("long", @LONG
這裡是銀針門的東走廊，一路走來，你不禁對南方的花
園產生極大的好奇心，帶著興奮的心情，迫不及待的要去看
看到底種了什麼東西 ？

LONG);

  set("light_up", 1);
	
	set("objects",([
 	]));
  set("exits", ([ /* sizeof() == 2 */
      "south" : __DIR__"d10",
      "west" : __DIR__"d6",
      ]));
  setup();
}
