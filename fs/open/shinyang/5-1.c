// Room: /u/w/whatup/area/shinyang/5-1
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "襄陽城南門");
  set ("long", @LONG
這裡是進入襄陽城的大城門口，門口的正上方寫著襄陽城三個字
，蒼勁有力的字跡，不知道是出自何人之手，這裡人來人往的十分熱
鬧，各式各樣的人在此經過，衛兵在四周忙碌的巡邏著。
LONG);

  set("outdoors", "/open");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"6-1.c",
  "west" : __DIR__"4-1.c",
  "north" : __DIR__"5-2.c",
  "south" : __DIR__"s_street.c",
]));
  set("no_auc", 1);
  set("no_transmit", 1);
  setup();
  create_door("south","南門大門","north",DOOR_OPENED );

}
