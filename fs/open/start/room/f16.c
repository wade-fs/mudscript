// Room: /open/start/room/f16.c

inherit ROOM;

void create ()
{
  set ("short", "稻田");
  set ("long", @LONG
你看到一片綠油油的稻田，空氣中充滿著稻草的氣味，
四處樹立的稻草人與辛勤工作的農夫們，構成了一幅標準的
農村景象，往北望去可以看到凌雲村。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/start/room/f21",
  "north" : "/open/start/room/f11",
  "east" : "/open/start/room/f17",
]));

  set("outdoors", "/open/start");

  setup();
}
