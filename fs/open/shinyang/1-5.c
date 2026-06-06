// Room: /u/w/whatup/area/shinyang/1-5.c
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "襄陽城西門");
  set ("long", @LONG
高聳的城門，抬頭望上看令人頭暈目眩，這麼高這麼寬的城門不
知道是如何興建起來的呢，這裡西門口出去似乎通往了河邊，不知道
是否就是前往中原的渡口，四周走動人的並不多，找不到一個合適可
以問路的人。
LONG);

  set("outdoors", "/open");
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"w_street.c",
  "east" : __DIR__"2-5.c",
  "north" : __DIR__"1-6.c",
  "south" : __DIR__"1-4.c",
]));
  set("no_auc", 1);
  set("no_transmit", 1);

  setup();
  create_door("west","西門大門","east",DOOR_OPENED );

}
