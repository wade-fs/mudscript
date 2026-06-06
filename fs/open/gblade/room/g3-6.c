#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "內院走道");
  set ("long", @LONG

這裡是金刀門王宅的內院，內院呈一個口字型，中間是一個花園，花園四
周是王元霸家眷的住處，你看看四周房間，門欄窗隔俱是細雕時新花樣，
並無朱粉塗飾。
南方是王家二小姐的住處。


LONG);

   set("light_up", 1);
   set("exits", ([ /* sizeof() == 4 */
   "east" :__DIR__"g3-7.c",
   "north" : __DIR__"g3-8.c",
   "west" : __DIR__"g3-5.c",
   "south": __DIR__"g3-6-1.c",
]));
 create_door("south", "雕花紫檀木門", "north", DOOR_CLOSED);

  setup();
}

