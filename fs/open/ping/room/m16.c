// Room: /open/ping/room/m16.c ~night~(小戀)

inherit ROOM;

void create ()
{
  set ("short", "小地道");
  set ("long", @LONG


這個地道一定就是通往風行山的路了,把地道做的這麼隱密,除了山上那些山賊外,大概沒有
人這麼無聊了,如果你想見識一下風行山賊的蠢樣,就繼續走下去吧!

LONG);

  set("objects", ([ /* sizeof() == 1 */
]));

  set("outdoors", "/open/ping");

  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"m17",
  "down" : __DIR__"m15",
]));

  setup();
}
