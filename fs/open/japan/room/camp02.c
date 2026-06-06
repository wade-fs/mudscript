#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "訓練場");
  set ("long", @LONG
這是守備隊平常訓練的場所，可以看到場上隊士們正捉對廝殺，
互相較量戰技。木刀交錯以及嘶吼的聲音不絕於耳。看起來守備隊除
了日常守備任務之外，平常也是相當注重戰技的訓練。往南是通往駐
地大門的方向。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"camp14.c",
    "north" : __DIR__"camp03.c",
    "south" : __DIR__"camp01.c",
  ]));
  create_door("south","門","north",DOOR_CLOSED);
  set("item_desc", ([ /* sizeof() == 1 */
    "south" : (: look_door, "north" :),
  ]));
  setup();
}

void reset()
{
  close_door("south");
  ::reset();
}
