// Room: /open/capital/room/j4
inherit ROOM;

void create ()
{
  set ("short", "地下密室");
  set ("long", @LONG
交談的聲音越來越近，前方也有些許光線。不由得想冒險犯難一番
，前去看看到底在搞甚麼鬼。往南是有樓梯的密室。兩邊仍然是佈滿青
苔的石壁。有幾個扶桑人守在這。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"j2",
  "north" : __DIR__"j3",
]));

  setup();
}
