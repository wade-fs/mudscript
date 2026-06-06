// Room: /open/capital/room/j2
inherit ROOM;

void create ()
{
  set ("short", "地下密室");
  set ("long", @LONG
交談的聲音越來越近，前方也有些許光線。不由得想冒險犯難一番
，前去看看到底在搞甚麼鬼。往南是有樓梯的密室。兩邊仍然是佈滿青
苔的石壁。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"j4",
  "south" : __DIR__"j1",
]));

  setup();
}
