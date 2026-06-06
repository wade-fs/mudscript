inherit ROOM;

void create()
{
  set ("short", "通道");
  set ("long", @LONG
西邊是隊士休息室，訓練或是巡邏結束的隊士正三三兩兩在屋簷
下休息。往北則是隊長以及兩位副隊長的專屬休息室，看起來似乎有
人在前面看守，避免有人隨意進入。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 4 */
    "east" : __DIR__"camp06.c",
    "west" : __DIR__"camp07.c",
    "north" : __DIR__"camp08.c",
    "south" : __DIR__"camp03.c",
  ]));
  setup();
}
