// Room: /u/d/dhk/questsfan/room8
//補上木柵的景觀線索 by blazakira 2011/6/14

inherit ROOM;

#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "絕崖的彼端");
  set ("long", @LONG
這裡的北面有一座大型的木柵，只有木柵的角邊留有
一道小門而且還上了鎖。這裡人煙罕至，難道此嶺有人居
住。不會是逃命到此的將軍吧？…
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
    "south" : __DIR__"room2",
    "east" : "/open/ping/questsfan/room9",
    "enter" : "/open/ping/questsfan/room10",
  ]));
  set("outdoors", "/u/d");
  set("need_key/out",1);
  create_door("enter",HIY"大木柵柵門"NOR,"out",DOOR_LOCKED);
  set("item_desc", ([ /* sizeof() == 1 */
    "enter" : (: look_door, "enter" :),
    "木柵" : (: look_door, "enter" :),
    "小門" : (: look_door, "enter" :),
  ]));
  setup();
}
