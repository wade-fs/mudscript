// Room: /u/e/eiei/room/troom_0.c
inherit ROOM;

void create ()
{
  set ("short", "後門出口");
  set ("long", @LONG
    這裡是雪蒼派的內廳後門，由窗外望去，可以看到
    一片綠油油的樹林，而且可能是靠近門口的關係，這裡
    的空氣比大廳內要好多了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room17.c",
  "east" : __DIR__"troom_1.c",
]));
  set("outdoors", "/open/snow/room");

  setup();
}
