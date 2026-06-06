#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"迷陣入口"NOR);
  set ("long", @LONG
虛幻的入口.飄邈的景象...似乎在訴說著這裡隱藏著無數的可能性
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room2/array0",
  "south" : "/open/gsword/room2/road1",
]));
  set("no_magic", 1);
  set("no_transmit", 1);
  set("no_fight",1);
  setup();
}
