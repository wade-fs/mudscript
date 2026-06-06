inherit ROOM;

void create()
{
  set ("short", "訓練場");
  set ("long", @LONG
這是守備隊平常訓練的場所，可以看到場上隊士們正捉對廝殺，
互相較量戰技。木刀交錯以及嘶吼的聲音不絕於耳。看起來守備隊除
了日常守備任務之外，平常也是相當注重戰技的訓練。往北似乎是守
備隊休息的地方，往東則是晒衣場。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"camp04.c",
    "east" : __DIR__"camp05.c",
    "west" : __DIR__"camp15.c",
    "south" : __DIR__"camp02.c",
  ]));
  setup();
}
