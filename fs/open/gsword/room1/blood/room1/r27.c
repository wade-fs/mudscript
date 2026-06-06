#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "血魔堡一樓");
  set ("long", @LONG
此為千年血魔在千年仙魔大戰前所建立的城堡，由於當年仙魔大戰
的緣故，使得此地處處斷垣殘壁，鬼魅之氣充斥於大氣間，你漸漸
受這片鬼氣影響而失去方向感了。

LONG);

  set("exits", ([ /* sizeof() == 5*/
  "west" : "/open/gsword/room1/blood/room1/r26.c",
  "east" : "/open/gsword/room1/blood/room1/r17.c",
  "north" : "/open/gsword/room1/blood/room1/r10.c",
  "south" : "/open/gsword/room1/blood/room1/r13.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );

  setup();
}
