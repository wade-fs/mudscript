inherit ROOM;

void create ()
{
  set ("short", "內院走道");
  set ("long", @LONG

這裡是金刀門王宅的內院，內院呈一個口字型，中間是一個花園，花園四
周是王元霸家眷的住處，你看看四周房間，門欄窗隔俱是細雕時新花樣，
並無朱粉塗飾。


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"b-room.c",
  "west" : __DIR__"g3-6.c",
  "north" : __DIR__"g2-4.c",
]));
  set("light_up", 1);

  setup();
}
