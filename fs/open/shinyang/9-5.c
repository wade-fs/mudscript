// Room: /u/w/whatup/area/shinyang/9-5
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "襄陽城東門");
  set ("long", @LONG
不知道位何這邊的城門是關閉著，因為關閉著所以這裡的光線的
十分微弱，城門陰暗的角落處似乎有人影在閃動，不知是何人躲在城
門裡，難道是四處乞討的的乞丐嗎？
LONG);

  set("outdoors", "/open");
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"e_street.c",
  "west" : __DIR__"8-5.c",
  "north" : __DIR__"9-6.c",
  "south" : __DIR__"9-4.c",
]));
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
  create_door("east","東門大門","west",DOOR_OPENED );
}
