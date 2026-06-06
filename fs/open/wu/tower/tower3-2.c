// Room: /u/p/pokai/room/wu/tower3-2
inherit ROOM;

void create()
{
  set ("short", "武威七殺塔三樓--");
  set ("long", @LONG
來到了這兒，你發現這裡一定經歷過相當慘烈的戰鬥，除了四布的血印以及滿牆
的掌印，還有一股股濕穢的黴味；你發覺牆角還有幾具殘缺的骷骨，你想這一些一定
是犧牲在這裡的武者們。
LONG );

  set("light_up", 0);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tower3-1",
  "east" : __DIR__"tower3-3",
]));
  setup();
}
