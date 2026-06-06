inherit ROOM;

void create()
{
  set ("short", "通道");
  set ("long", @LONG
往北則是隊長以及兩位副隊長的專屬休息室，看起來似乎有人在
前面看守，避免有人隨意進入。往南通往訓練場。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"camp09.c",
    "south" : __DIR__"camp04.c",
  ]));
  setup();
}
