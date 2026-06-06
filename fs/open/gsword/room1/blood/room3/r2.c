#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "天魔血路");
  set ("long", @LONG
隨著你一步一步踏入血魔主城...你感到一陣陣的血腥味撲鼻而來
地上各式各樣不同生物的骨骸令你心生怯意...萌生退後的念頭..
此通道呈直線形....似乎就要到血魔主城了。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "north" : "/open/gsword/room1/blood/room3/r3.c",
  "south" : "/open/gsword/room1/blood/room3/r1.c",

]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  setup();
}
