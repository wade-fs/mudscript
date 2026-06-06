// Room: /open/capital/room/r41.c

inherit ROOM;

void create ()
{
  set ("short", "永福胡同");
  set ("long", @LONG
雜草叢生的石板路。往東北去是日升馳道。南邊遠遠看到幾座烽火
台。這些烽火台是京城遭襲時向鎮守各邊關的大將求援用的。這幾年天
下太平，烽火台的狼煙已經好久沒有燃過了。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"r42",
  "west" : __DIR__"r39",
]));
  set("gopath", "west");

  setup();
}
