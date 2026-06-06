#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "內院走道");
  set ("long", @LONG

這裡是金刀門王宅的內院，內院呈一個口字型，中間是一個花園，花園四
周是王元霸家眷的住處，你看看四周房間，門欄窗隔俱是細雕時新花樣，
並無朱粉塗飾。
北邊是王元霸的房間。

LONG);

   set("light_up", 1);
   set("exits", ([ /* sizeof() == 4 */
   "south" :__DIR__"g3-8.c",
   "west" :__DIR__"g3-3.c",
   "north" : __DIR__"g3-2-1.c",
   "east" : __DIR__"g3-1.c",
]));
create_door("north", "雕花紫檀木門", "south", DOOR_CLOSED);

  setup();
}

