// Room: /open/capital/room/r21.c

inherit ROOM;

void create ()
{
  set ("short", "豐安橋");
  set ("long", @LONG
往南是日落馳道，往北有條較小的胡同。這是座白色的大拱橋，跨
過一條不算小的溪，溪裡的水流得很緩慢，幾乎沒有在動。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/capital/room/r20",
  "south" : "/open/capital/room/r22",
]));

  set("gopath", "north");

  setup();
}
