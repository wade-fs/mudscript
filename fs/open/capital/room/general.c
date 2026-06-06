// Room: /open/capital/room/general
inherit ROOM;

void create ()
{
  set ("short", "鎮遠侯府前");
  set ("long", @LONG
你來到了鼎鼎大名的鎮遠侯府, 前方幢立了一棟三層樓的屋宇, 整
棟漆成了大紅色, 粱上盤踞著一條八爪金龍, 徐徐如生, 使你錯覺到龍
的鬍鬚似乎隨風飄動。屋子的大門大開, 好像在歡迎你的來臨。

LONG);

  set("light_up", 1);


  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/capital/room/r55",
]));

  setup();
}
