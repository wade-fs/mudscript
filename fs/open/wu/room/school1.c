// Room: /open/wu/room/school1.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "正晴武館大門");
  set ("long", @LONG
你正站在一座建築宏偉的宅第之前, 左右兩座石壇中各豎一根兩丈
來高的旗杆, 杆頂飄揚著青旗, 旗上繡著"正晴武館"四個黑字,大宅生
漆大門,門上茶杯大小的金環閃閃發光,門頂匾額寫著"拳傾天下"四個金
漆大字．也許你可以試著打開大門(open door).
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/ping/room/inn",
  "east" : __DIR__"school2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  create_door("east", HIR"鏤花紅檜大門"NOR, "west", DOOR_CLOSED);
  set("light_up", 1);
  setup();
}
