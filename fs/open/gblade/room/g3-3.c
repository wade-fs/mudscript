#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "內院走道");
  set ("long", @LONG

這裡是金刀門王宅的內院，內院呈一個口字型，中間是一個花園，花園四
周是王元霸家眷的住處，你看看四周房間，門欄窗隔俱是細雕時新花樣，
並無朱粉塗飾。
北邊是王元霸獨子的臥房。


LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"g3-4.c",
	"west"  : __DIR__"p-room",
  "north" : __DIR__"g3-3-1.c",
  "east" : __DIR__"g3-2.c",
]));
  set("light_up", 1);
	create_door("north", "雕花紫檀木門", "south", DOOR_CLOSED);

  setup();
}
